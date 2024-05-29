import os
import tempfile

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch_ros.actions import Node

import xacro

def generate_launch_description():
    # Loading URDF file into a parameter
    bringup_dir = get_package_share_directory('my_second_delta')
    urdf_path = os.path.join(bringup_dir, 'urdf', 'delta.urdf.xacro')
    robot_raw_description = xacro.process_file(urdf_path).toxml()

    # Write the URDF to a temporary file
    urdf_file = tempfile.NamedTemporaryFile(delete=False)
    urdf_file.write(robot_raw_description.encode())
    urdf_file.close()

    return LaunchDescription([
        Node(
            package='gazebo_ros', 
            executable='spawn_entity.py',
            arguments=['-entity', 'delta', '-file', urdf_file.name],
            output='screen'
        ),


        Node(
            package='robot_state_publisher', executable='robot_state_publisher',
            output='screen'
        ),

        Node(
            package='rviz2', executable='rviz2',
            arguments=['-d', os.path.join(bringup_dir + '/config/config_file.rviz')],
            output='screen'
        ),

        ])

