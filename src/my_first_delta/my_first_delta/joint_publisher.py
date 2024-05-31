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
        self.publisher_ = self.create_publisher(JointState, 'joint_states', qos)
        self.subscriber = self.create_subscription(Float64MultiArray, 'excel_coordinates', self.end_position_listener, qos)

        self.x = 0.0
        self.y = 0.0
        self.z = -300.0

        self.degrees = [0.0, 0.0, 0.0]

        self.received_response = False 

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
                self.degrees = [future.result().theta1, future.result().theta2, future.result().theta3]
                self.received_response = True  
                msg = JointState()
                msg.header.stamp = self.get_clock().now().to_msg()
                msg.name = ['base_to_arm_1', 'base_to_arm_2', 'base_to_arm_3']
                msg.position = [math.radians(rad) for rad in self.degrees]  
                msg.velocity = [1.0, 1.0, 1.0]  # Replace with actual velocity if available
                msg.effort = [0.0, 0.0, 0.0]  # Replace with actual effort if available
                self.publisher_.publish(msg)
                print(msg.position)
                self.get_logger().info('Rotating base_to_arm joint: "%f" radians' % msg.position[0])

        
def main(args=None):
    rclpy.init(args=args)

    joint_publisher = JointPublisher()

    rclpy.spin(joint_publisher)

    joint_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
