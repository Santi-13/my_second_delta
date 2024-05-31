import os
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, ExecuteProcess
from launch.substitutions import LaunchConfiguration
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    moveit_config_dir = get_package_share_directory('delta_moveit_config')
    rviz_config_file = os.path.join(moveit_config_dir, 'config', 'moveit.rviz')

    return LaunchDescription([
        DeclareLaunchArgument(
            'rviz_config_file',
            default_value=rviz_config_file,
            description='Full path to the RVIZ config file to use'
        ),
        ExecuteProcess(
            cmd=['rviz2', '-d', LaunchConfiguration('rviz_config_file')],
            output='screen'
        )
    ])
