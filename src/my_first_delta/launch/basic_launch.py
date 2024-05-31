import os
import sys

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    # Loading URDF file into a parameter
    bringup_dir = get_package_share_directory('my_first_delta')
    urdf_path = os.path.join(bringup_dir, 'urdf', 'base.urdf.xacro')
    urdf = open(urdf_path).read()

    return LaunchDescription([
        Node(
            package='rviz2', 
            executable='rviz2', 
            arguments=['-d',
                       'install/my_first_delta/share/my_first_delta/basic_launch.rviz',
                       '-d' + os.path.join(bringup_dir, 'config', 'config_file.rviz')],
            output='screen',
        ),
        Node(
            name='robot_state_publisher',
            package='robot_state_publisher',
            executable='robot_state_publisher',
            parameters=[{'robot_description': urdf, 'use_tf_static': False}]
        ),
        #Node(
        #    name='joint_state_publisher',
        #    package='joint_state_publisher',
        #    executable='joint_state_publisher',
        #    parameters=[{'robot_description': urdf}]
        #),
        Node(
            package='my_first_delta',
            name='inverse_kinematics_server',
            executable='inverse_kinematics_server'
        ),
        Node(
            package='my_first_delta',
            name='joint_publisher',
            executable='joint_publisher'
        ),
        Node(
            package='my_first_delta',
            name='excel_publisher',
            executable='excel_publisher'
        ),

    ])
