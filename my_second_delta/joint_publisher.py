import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
from rclpy.qos import QoSProfile, QoSHistoryPolicy

from more_interfaces.srv import DeltaTheta
from std_msgs.msg import Float64MultiArray

import math

class JointPublisher(Node):
    def __init__(self):
        qos = QoSProfile(history=QoSHistoryPolicy.KEEP_LAST, depth=30)
        super().__init__('joint_publisher')

        self.cli = self.create_client(DeltaTheta, 'get_delta_theta')       
        self.publisher_ = self.create_publisher(Float64MultiArray, 'joint_torque_controller/commands', qos)
        self.subscriber = self.create_subscription(JointState, 'joint_states', self.joint_state_listener, qos)
        self.target_subscriber = self.create_subscription(Float64MultiArray, 'excel_coordinates', self.end_position_listener, qos)

        self.x = 0.0
        self.y = 0.0
        self.z = -300.0

        self.degrees = [0.0, 0.0, 0.0]
        self.current_positions = [0.0, 0.0, 0.0]

        self.received_response = False 
        self.kp = 10.0   # Proportional Gain

    def end_position_listener(self, msg):
        self.x = msg.data[0]
        self.y = msg.data[1]
        self.z = msg.data[2]
        self.get_logger().info('I received the end position')

        self.call_service(self.x, self.y, self.z)            
           
    def call_service(self, x, y, z):
        if not self.cli.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
        else:
            self.req = DeltaTheta.Request()  
            self.req.x = x
            self.req.y = y
            self.req.z = z
            self.future = self.cli.call_async(self.req)
            self.future.add_done_callback(self.handle_service_response)


    def handle_service_response(self, future):
        if future.done():
            if future.result() is not None:
                self.degrees = [math.radians(future.result().theta1), math.radians(future.result().theta2), math.radians(future.result().theta3)]
                self.received_response = True  
                self.get_logger().info('Rotating arm1: %f rad | arm2: %f rad | arm3: %f rad' % (self.degrees[0], self.degrees[1], self.degrees[2]))


    def joint_state_listener(self, msg):
        if len(msg.position) >= 3:
            self.current_positions = msg.position[:3]
            self.control_loop()

    def control_loop(self):
        errors = [desired - current for desired, current in zip(self.degrees, self.current_positions)]
        torques = [error * self.kp for error in errors]
        msg = Float64MultiArray()
        msg.data = torques
        self.publisher_.publish(msg)
        self.get_logger().info('Applying torques: %f Nm | %f Nm | %f Nm' % (torques[0], torques[1], torques[2]))

        
def main(args=None):
    rclpy.init(args=args)

    joint_publisher = JointPublisher()

    rclpy.spin(joint_publisher)

    joint_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
