from more_interfaces.srv import DeltaTheta
import sys
import rclpy
from rclpy.node import Node


class InverseKinematicsClient(Node):
    def __init__(self):
        super().__init__('inverse_kinematics_client_async')
        self.cli = self.create_client(DeltaTheta, 'get_delta_theta')       
        while not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
        self.req = DeltaTheta.Request()                                   

    def send_request(self):
        self.req.x = float(sys.argv[1])
        self.req.y = float(sys.argv[2])
        self.req.z = float(sys.argv[3])                                       
        self.future = self.cli.call_async(self.req)


def main(args=None):
    rclpy.init(args=args)

    minimal_client = InverseKinematicsClient()
    minimal_client.send_request()

    while rclpy.ok():
        rclpy.spin_once(minimal_client)
        if minimal_client.future.done():
            try:
                response = minimal_client.future.result()
            except Exception as e:
                minimal_client.get_logger().info(
                    'Service call failed %r' % (e,))
            else:
                minimal_client.get_logger().info(
                    'Result of get_delta_theta for:\nx: %d y: %d z: %d\ntheta1: %d theta2: %d theta3: %d' %                                
                    (minimal_client.req.x, minimal_client.req.y, minimal_client.req.z, response.theta1, response.theta2, response.theta3))  
            break

    minimal_client.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()