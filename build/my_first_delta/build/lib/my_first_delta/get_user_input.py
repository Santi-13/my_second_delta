import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64MultiArray

class UserInputPublisher(Node):
    def __init__(self):
        super().__init__('user_input_publisher')
        self.publisher_ = self.create_publisher(Float64MultiArray, 'desired_end_position', 10)
        timer_period = 1.0/2  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)

    def get_user_input(self):
        x = float(input("Enter x: "))
        y = float(input("Enter y: "))
        z = float(input("Enter z: "))
        return x, y, z

    def timer_callback(self):
        x, y, z = self.get_user_input()
        msg = Float64MultiArray()
        msg.data = [x, y, z]
        self.publisher_.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    user_input_publisher = UserInputPublisher()
    rclpy.spin(user_input_publisher)
    user_input_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
