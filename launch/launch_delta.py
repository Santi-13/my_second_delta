import os

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node

def generate_launch_description():
    # Loading URDF file into a parameter
    bringup_dir = get_package_share_directory('my_second_delta')
    urdf_path = os.path.join(bringup_dir, 'urdf', 'delta.urdf')

    with open(urdf_path, 'r') as urdf_file:
        robot_description_content = urdf_file.read()

    return LaunchDescription([
        Node(
            package='rviz2', 
            executable='rviz2', 
            arguments=['-d',
                       'install/my_second_delta/share/my_second_delta/launch_delta.rviz',
                       '-d' + os.path.join(bringup_dir, 'config', 'config_file.rviz')],
            output='screen',
        ),
        Node(
            package='robot_state_publisher', 
            executable='robot_state_publisher', 
            output='screen',
            parameters=[{'robot_description': robot_description_content}],
        ),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource([os.path.join(
                get_package_share_directory('gazebo_ros'), 'launch'), '/gazebo.launch.py']),
        ),
        Node(
            package='gazebo_ros',
            executable='spawn_entity.py',
            arguments=['-entity', 'delta', '-topic', 'robot_description'],
            output='screen',
        ),
        # Node(
        #     name='joint_state_publisher',
        #     package='joint_state_publisher',
        #     executable='joint_state_publisher',
        #     parameters=[{'robot_description': robot_raw_description}]
        # ),
    ])