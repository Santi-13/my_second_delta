import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64MultiArray
from rclpy.qos import QoSProfile, QoSHistoryPolicy
from snap7.util import *
from snap7.types import *
import snap7

import time
import struct

class PLCReaderWriterNode(Node):
    def __init__(self):
        super().__init__('plc_reader')
        qos = QoSProfile(history=QoSHistoryPolicy.KEEP_LAST, depth=10)
        self.publisher_ = self.create_publisher(Float64MultiArray, 'plc_tags_read', qos)
        self.subscription = self.create_subscription(
            Float64MultiArray,
            'plc_tags_write',
            self.listener_callback,
            qos)
        timer_period = 0.2  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.subscription  # Prevent unused subscription warning
        self.plc = None
        self.db_number = 14 
        self.timeout_duration = 10  # Timeout duration in seconds
        self.start_time = time.time()
        self.connect_to_plc()

    def connect_to_plc(self):
        self.plc = snap7.client.Client()
        while not self.plc.get_connected():
            try:
                self.plc.disconnect()
                # attempt connection
                self.get_logger().info('Trying to connect to PLC...')
                self.plc.connect('192.168.0.1', 0, 1)
            except Exception:
                pass
            time.sleep(1)        
        self.get_logger().info('Connected to PLC!')

    def ensure_connection(self):
        if not self.plc.get_connected():
            self.get_logger().warn("PLC disconnected. Attempting to reconnect...")
            self.connect_to_plc()

    def read_coordinates_from_plc(self):
        self.ensure_connection()
        try:
            # Addresses for the values
            enemy_row_address = 0  
            enemy_col_address = 1
            play_row_address  = 2
            play_col_address  = 3
            start_tictactoe_address = 6
            starting_tictactoe_player_address = 7

            x_address = 8   # Example address for X coordinate
            y_address = 12  # Example address for Y coordinate
            z_address = 16  # Example address for Z coordinate
                            

            enemy_row = self.plc.db_read(self.db_number, enemy_row_address, 1)
            enemy_col = self.plc.db_read(self.db_number, enemy_col_address, 1)
            play_row  = self.plc.db_read(self.db_number, play_row_address, 1)
            play_col  = self.plc.db_read(self.db_number, play_col_address, 1)
            start_tictactoe = self.plc.db_read(self.db_number, start_tictactoe_address, 1)
            starting_tictactoe_player = self.plc.db_read(self.db_number, starting_tictactoe_player_address, 1)
            x_value = self.plc.db_read(self.db_number, x_address, 4)
            y_value = self.plc.db_read(self.db_number, y_address, 4)
            z_value = self.plc.db_read(self.db_number, z_address, 4)
            
            enemy_row_int = struct.unpack('b', enemy_row)[0]
            enemy_col_int = struct.unpack('b', enemy_col)[0]
            play_row_int  = struct.unpack('b', play_row)[0]
            play_col_int  = struct.unpack('b', play_col)[0]
            start_tictactoe_bool = struct.unpack('b', start_tictactoe)[0] 
            starting_tictactoe_player_int = struct.unpack('b', starting_tictactoe_player)[0] 
            # Convert the read bytes to floats
            x_float = snap7.util.get_real(x_value, 0)
            x_float = -x_float
            y_float = snap7.util.get_real(y_value, 0)
            z_float = snap7.util.get_real(z_value, 0)
            data = [x_float, y_float, z_float, enemy_row_int, enemy_col_int, starting_tictactoe_player_int, start_tictactoe_bool, play_row_int, play_col_int]
            return data
        except Exception as e:
            self.get_logger().error(f"Error reading from PLC: {e}. Attempting to reconnect.")
            self.connect_to_plc()
            time.sleep(1)
            return [0, 0, -310.0, 0, 0, 0, 0, 0, 0]

    def listener_callback(self, msg):
        self.ensure_connection()
        try:
            # Ensure we have connected to the PLC
            if self.plc is None:
                self.connect_to_plc()  # Replace with your PLC IP

            # Extract the coordinates from the message
            x_coord     =   int(msg.data[0])
            y_coord     =   int(msg.data[1])
            game_ended  =   int(msg.data[2])
            game_won    =   int(msg.data[3])
            x_plus      =   int(msg.data[4])
            x_minus     =   int(msg.data[5])
            y_plus      =   int(msg.data[6])
            y_minus     =   int(msg.data[7])
            z_plus      =   int(msg.data[8])
            z_minus     =   int(msg.data[9])

            # Convert the coordinates to bytes (assuming 16-bit integers)
            first_coord_bytes = x_coord.to_bytes(1, byteorder='big') + y_coord.to_bytes(1, byteorder='big') + game_ended.to_bytes(1, byteorder='big') + game_won.to_bytes(1, byteorder='big') 
            second_coord_bytes = x_plus.to_bytes(1, byteorder='big') + x_minus.to_bytes(1, byteorder='big') + y_plus.to_bytes(1, byteorder='big') + y_minus.to_bytes(1, byteorder='big') + z_plus.to_bytes(1, byteorder='big') + z_minus.to_bytes(1, byteorder='big') 


            # Write the coordinates to the PLC memory
            try:
                self.plc.db_write(self.db_number, 2, first_coord_bytes)
                self.plc.db_write(self.db_number, 20, second_coord_bytes)

                self.get_logger().info(f"Wrote coordinates ({x_coord}, {y_coord}) to PLC memory at address 2")
            except Exception as e:
                self.get_logger().error(f"Failed to write to PLC memory: {str(e)}")
        except Exception as e:
            self.get_logger().error(f"Error writing to PLC: {e}. Attempting to reconnect.")
            self.connect_to_plc()
            time.sleep(1)


    def timer_callback(self):
        msg = Float64MultiArray()
        msg.data = self.read_coordinates_from_plc()
        self.publisher_.publish(msg)
        self.get_logger().info('Published coordinates: %s' % msg.data)


def main(args=None):
    rclpy.init(args=args)
    plc_reader_writer_node = PLCReaderWriterNode()
    rclpy.spin(plc_reader_writer_node)
    plc_reader_writer_node.plc.disconnect()
    plc_reader_writer_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
