from more_interfaces.srv import DeltaTheta

import rclpy
from rclpy.node import Node

import numpy as np

class InverseKinematicsServer(Node):
    def __init__(self):
        super().__init__('inverse_kinematics_server')
        self.srv = self.create_service(DeltaTheta, 'get_delta_theta', self.inverse_kinematics_callback)
        self.l1 = 150
        self.l2 = 375.25
        self.rho_p = -29.501
        self.rho_b = -106.478

    def rotz(self, deg):
        rot = np.matrix([[np.cos(deg),      -np.sin(deg),       0],
                        [np.sin(deg),       np.cos(deg),        0],
                        [0,                 0,                  1]
                        ], float)
        return rot

    def inverse_kinematics_callback(self, request, response):
        theta = np.zeros((3,1), float)

        for i in range(0,3):
            pos_i = np.matmul(self.rotz((120*np.pi/180)*i), np.matrix([[request.x], [request.y], [request.z]], float))   
            x_i = pos_i[0]
            y_i = pos_i[1]
            z_i = pos_i[2]

            h = np.sqrt( self.l2**2 - x_i**2 )
            r = np.sqrt( ( y_i + self.rho_p - self.rho_b )**2 + z_i**2 )

            theta[i] = 90 + np.arcsin( (y_i + self.rho_p - self.rho_b ) / r ) * 180 / np.pi - np.arccos( ( r**2 + self.l1**2 - h**2 ) / ( 2 * self.l1 * r ) ) * 180 / np.pi

        response.theta1 = theta[0][0]
        response.theta2 = theta[1][0]
        response.theta3 = theta[2][0]

        if(np.isnan(response.theta1) or np.isnan(response.theta2) or np.isnan(response.theta3)):
            raise Exception("Coordinates outside of workspace")

        self.get_logger().info('Incoming request\nx: %d y: %d z: %d' % (request.x, request.y, request.z))
        self.get_logger().info('Response dispatched\ntheta1: %d theta2: %d theta3: %d' % (response.theta1, response.theta2, response.theta3))

        return response


def main():
    rclpy.init()

    inverse_kinematics_server = InverseKinematicsServer()

    rclpy.spin(inverse_kinematics_server)

    rclpy.shutdown()


if __name__ == '__main__':
    main()