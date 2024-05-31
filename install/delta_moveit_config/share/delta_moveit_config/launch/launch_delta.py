import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.substitutions import Command, LaunchConfiguration
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_share_directory
from launch_ros.actions import Node

def generate_launch_description():
    moveit_config_dir = get_package_share_directory('delta_moveit_config')
    description_launch = os.path.join(get_package_share_directory('my_third_delta'), 'launch', 'launch_delta.launch.py')

    return LaunchDescription([
        DeclareLaunchArgument(
            'use_sim_time', default_value='false',
            description='Use simulation time'
        ),
        DeclareLaunchArgument(
            'robot_description_file',
            default_value=os.path.join(get_package_share_directory('my_third_delta'), 'urdf', 'delta.urdf.xacro'),
            description='Absolute path to robot urdf file'
        ),
        DeclareLaunchArgument(
            'color', default_value='blue',
            description='Color of the robot'
        ),
        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            output='screen',
            parameters=[{
                'use_sim_time': LaunchConfiguration('use_sim_time'),
                'robot_description': Command([
                    'xacro ', LaunchConfiguration('robot_description_file'),
                    ' color:=', LaunchConfiguration('color')
                ])
            }]
        ),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(os.path.join(moveit_config_dir, 'launch', 'move_group.launch.py'))
        ),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(os.path.join(moveit_config_dir, 'launch', 'rviz.launch.py'))
        )
    ])
