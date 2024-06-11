from launch import LaunchDescription

from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        Node(
            package='my_second_delta',
            name='plc_reader_writer',
            executable='plc_reader_writer'
        ),
        Node(
            package='my_second_delta',
            name='tictactoe_player',
            executable='tictactoe_player'
        )
    ])