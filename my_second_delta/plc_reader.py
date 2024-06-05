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
        self.plc.set_connection_type(snap7.types.AT.S7_1200)
        self.plc.set_connection_params('192.168.0.100', 0, 1)  # IP, Rack, Slot
        if not self.plc.get_connected():
            self.plc.connect()

    def read_coordinates_from_plc(self):
        x_address = 0  # Example address for X coordinate
        y_address = 4  # Example address for Y coordinate
        z_address = 8  # Example address for Z coordinate

        # Reading Real values requires specifying the data block (DB) number and the start address within that DB
        # Assuming the Real values are stored in DB1 starting at byte offsets corresponding to M12, M16, M20
        db_number = 1  # Example DB number, adjust based on your PLC program
        x_value = self.plc.db_read(db_number, x_address, S7WLReal)
        y_value = self.plc.db_read(db_number, y_address, S7WLReal)
        z_value = self.plc.db_read(db_number, z_address, S7WLReal)
        data = [x_value, y_value, z_value]
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
