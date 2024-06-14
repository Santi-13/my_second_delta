import rclpy
from rclpy.node import Node
from pynput import keyboard
from std_msgs.msg import Float64MultiArray
from rclpy.qos import QoSProfile, QoSHistoryPolicy

class TeleopKeyboard(Node):
    def __init__(self):
        super().__init__('teleop_keyboard')
        qos = QoSProfile(history=QoSHistoryPolicy.KEEP_LAST, depth=10)
        self.publisher_ = self.create_publisher(Float64MultiArray, 'plc_tags_write', qos)
        self.subscription = self.create_subscription(
            Float64MultiArray,
            'pre_plc_tags_write',
            self.listener_callback,
            qos)
        self.listener = keyboard.Listener(on_press=self.on_key_press, on_release=self.on_key_release)
        self.listener.start()  # Start the listener
        self.directions = {'x_plus': 0, 'x_minus': 0, 'y_plus': 0, 'y_minus': 0, 'z_plus': 0, 'z_minus': 0}

    def on_key_press(self, key):
        try:
            char = key.char
            if char == 'w':
                self.directions['x_plus'] = 1
                self.get_logger().info("w Pressed.")

            elif char == 's':
                self.directions['x_minus'] = 1
            elif char == 'a':
                self.directions['y_plus'] = 1
            elif char == 'd':
                self.directions['y_minus'] = 1
            elif char == 'q':
                self.directions['z_plus'] = 1
            elif char == 'e':
                self.directions['z_minus'] = 1
        except AttributeError:
            pass

    def on_key_release(self, key):
        try:
            char = key.char
            if char in ['w', 's']:
                self.directions['x_plus'] = 0
                self.directions['x_minus'] = 0
            elif char in ['a', 'd']:
                self.directions['y_plus'] = 0
                self.directions['y_minus'] = 0
            elif char in ['q', 'e']:
                self.directions['z_plus'] = 0
                self.directions['z_minus'] = 0
        except AttributeError:
            pass

    def listener_callback(self, msg):
        # Initialize a new Float64MultiArray message
        pub_msg = Float64MultiArray()
        
        # Copy the received data
        pub_msg.data = msg.data
        
        # Update the directions in the message
        pub_msg.data.extend([self.directions['x_plus'], self.directions['x_minus'],
                             self.directions['y_plus'], self.directions['y_minus'],
                             self.directions['z_plus'], self.directions['z_minus']])
        self.get_logger().info("Sending Data...")

        # Publish the updated message
        self.publisher_.publish(pub_msg)

def main(args=None):
    rclpy.init(args=args)
    teleop_node = TeleopKeyboard()
    try:
        rclpy.spin(teleop_node)
    except KeyboardInterrupt:
        pass
    finally:
        teleop_node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
