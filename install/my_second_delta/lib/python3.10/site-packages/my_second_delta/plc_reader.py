import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64MultiArray
from rclpy.qos import QoSProfile, QoSHistoryPolicy
from snap7.util import *
from snap7.types import *
import snap7

class PLCReaderNode(Node):
    def __init__(self):
        super().__init__('plc_reader')
        qos = QoSProfile(history=QoSHistoryPolicy.KEEP_LAST, depth=10)
        self.publisher_ = self.create_publisher(Float64MultiArray, 'coordinates', qos)
        timer_period = 1  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.plc = None
        self.connect_to_plc()

    def connect_to_plc(self):
        self.plc = snap7.client.Client()
        while not self.plc.get_connected():
            try:
                self.plc.disconnect()
                # attempt connection
                self.get_logger().info('Trying to connect to PLC...')
                self.plc.connect('192.168.0.15', 0, 1)
            except Exception:
                pass
            time.sleep(1)        
        self.get_logger().info('Connected to PLC!')

    def read_coordinates_from_plc(self):
        # Addresses for the Real values
        x_address = 32  # Example address for X coordinate
        y_address = 28  # Example address for Y coordinate
        z_address = 36  # Example address for Z coordinate
             
        db_number = 1 

        x_value = self.plc.db_read(db_number, x_address, 4)
        y_value = self.plc.db_read(db_number, y_address, 4)
        z_value = self.plc.db_read(db_number, z_address, 4)
        
        # Convert the read bytes to floats
        x_float = snap7.util.get_real(x_value, 0)
        y_float = snap7.util.get_real(y_value, 0)
        z_float = snap7.util.get_real(z_value, 0)
        data = [x_float, y_float, z_float]
        return data

    def timer_callback(self):
        msg = Float64MultiArray()
        msg.data = self.read_coordinates_from_plc()
        self.publisher_.publish(msg)
        self.get_logger().info('Published coordinates: %s' % msg.data)


def main(args=None):
    rclpy.init(args=args)
    plc_reader_node = PLCReaderNode()
    rclpy.spin(plc_reader_node)
    plc_reader_node.plc.disconnect()
    plc_reader_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
