import os

import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64MultiArray
from rclpy.qos import QoSProfile, QoSHistoryPolicy
import pandas as pd

from ament_index_python.packages import get_package_share_directory

class ExcelPublisher(Node):
    def __init__(self, excel_file):
        super().__init__('excel_publisher')
        qos = QoSProfile(history=QoSHistoryPolicy.KEEP_LAST, depth=10)
        self.publisher_ = self.create_publisher(Float64MultiArray, 'excel_coordinates', qos)
        self.df = pd.read_excel(excel_file)  # Read the Excel file
        self.index = 0  # Index to keep track of the current row in the Excel file
        timer_period = 1.0/31  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)

    def timer_callback(self):
        if self.index >= len(self.df):
            self.index = 0  # Reset the index if we've read all rows
        row = self.df.iloc[self.index]
        msg = Float64MultiArray()
        msg.data = [row['x'], row['y'], row['z']]  # Replace 'x', 'y', 'z' with your column names
        self.publisher_.publish(msg)
        self.get_logger().info('Published coordinates: %s' % msg.data)
        self.index += 1

def main(args=None):
    rclpy.init(args=args)

    excel_publisher = ExcelPublisher(os.path.join(get_package_share_directory('my_second_delta'), 'data', 'coordinates.xlsx'))  # Replace with your Excel file name

    rclpy.spin(excel_publisher)

    excel_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
