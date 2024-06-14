import os

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.substitutions import Command, FindExecutable, LaunchConfiguration, PathJoinSubstitution
from launch.actions import DeclareLaunchArgument, RegisterEventHandler, SetEnvironmentVariable, IncludeLaunchDescription
from launch.conditions import IfCondition
from launch.event_handlers import OnProcessExit
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


import xacro

def generate_launch_description():
    # Loading URDF file into a parameter
    bringup_dir = get_package_share_directory('my_second_delta')
    xacro_path = os.path.join(bringup_dir, 'urdf', 'delta.urdf.xacro')
    robot_description_content = xacro.process_file(xacro_path).toxml()
    world_path = os.path.join(bringup_dir, 'worlds', 'delta_world.world')


    ros2_control_config_path = os.path.join(bringup_dir, 'config', 'delta_joint_position.yaml')

    declared_arguments = []
    declared_arguments.append(
        DeclareLaunchArgument(
            'use_sim_time',
            default_value='true',
            description='Use simulation (Gazebo) clock if true',
        )
    )
    declared_arguments.append(
        DeclareLaunchArgument(
            "prefix",
            default_value='""',
            description="Prefix of the joint names, useful for \
        multi-robot setup. If changed than also joint names in the controllers' configuration \
        have to be updated.",
        )
    )
    declared_arguments.append(
        DeclareLaunchArgument(
            "use_mock_hardware",
            default_value="false",
            description="Start robot with mock hardware mirroring command to its states.",
        )
    )
    declared_arguments.append(
        DeclareLaunchArgument(
            "mock_sensor_commands",
            default_value="false",
            description="Enable mocked command interfaces for sensors used for simple simulations. \
            Used only if 'use_mock_hardware' parameter is true.",
        )
    )
    declared_arguments.append(
        DeclareLaunchArgument(
            "slowdown", default_value="50.0", description="Slowdown factor of the RRbot."
        ),
    )
    declared_arguments.append(
        DeclareLaunchArgument(
            "gui",
            default_value="true",
            description="Start RViz2 automatically with this launch file.",
        ),
    )
    declared_arguments.append(
        DeclareLaunchArgument(
            "robot_controller",
            default_value="joint_torque_controller",
            description="Robot controller to start.",
        ),
    )      
    declared_arguments.append(
        DeclareLaunchArgument(
            'server', 
            default_value='true',
            description='Whether to start gzserver'
        )
    )
    declared_arguments.append(
        DeclareLaunchArgument(
            "world", 
            default_value=world_path,
            description='Full path to the world model file to load'
        )
    )
        
    

    # Initialize launch parameters
    prefix = LaunchConfiguration("prefix")
    use_mock_hardware = LaunchConfiguration("use_mock_hardware")
    mock_sensor_commands = LaunchConfiguration("mock_sensor_commands")
    slowdown = LaunchConfiguration("slowdown")
    robot_controller = LaunchConfiguration("robot_controller")
    gui = LaunchConfiguration("gui")
    use_sim_time = LaunchConfiguration("use_sim_time")
    gz_server = LaunchConfiguration('server')
    world_arg = LaunchConfiguration("world")

    # Get URDF via xacro
    robot_description_content = Command(
        [
            PathJoinSubstitution([FindExecutable(name="xacro")]),
            " ",
            PathJoinSubstitution(
                [
                    FindPackageShare("my_second_delta"),
                    "urdf",
                    "delta.urdf.xacro",
                ]
            ),
            " ",
            "prefix:=",
            prefix,
            " ",
            "use_mock_hardware:=",
            use_mock_hardware,
            " ",
            "mock_sensor_commands:=",
            mock_sensor_commands,
            " ",
            "slowdown:=",
            slowdown,
        ]
    )
    robot_description = {'robot_description': robot_description_content, 'use_sim_time': use_sim_time}

    robot_controllers = PathJoinSubstitution(
        [
            FindPackageShare("my_second_delta"),
            "config",
            "delta_joint_position.yaml",
        ]
    )
    print(robot_controllers)

    # Nodes Initialization
    gazebo_ros_node = Node(
        package='gazebo_ros',
        executable='spawn_entity.py',
        arguments=['-entity', 'delta', '-topic', 'robot_description'],
        output='screen',
    )

    control_node = Node(
        package="controller_manager",
        executable="ros2_control_node",
        parameters=[robot_controllers],
        output="both",
        remappings=[
            ("~/robot_description", "/robot_description"),
        ],
    )
    
    robot_state_pub_node = Node(
        package='robot_state_publisher', 
        executable='robot_state_publisher', 
        output='screen',
        parameters=[robot_description],
    )

    rviz2_node = Node(
        package='rviz2', 
        executable='rviz2', 
        name='rviz2',
        arguments=['-d' + os.path.join(bringup_dir, 'config', 'config_file.rviz')],
        output='screen',
        condition=IfCondition(gui),
    )

    joint_state_broadcaster_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["joint_state_broadcaster", "--controller-manager", "/controller_manager"],
    )

    robot_controller_spawner = Node(
        package='controller_manager',
        executable='spawner',
        arguments=[robot_controller, '--controller-manager', '/controller_manager'],
    )

    plc_reader_writer_node = Node(
        package='my_second_delta',
        name='plc_reader_writer',
        executable='plc_reader_writer'
    )

    tictactoe_player_node = Node(
        package='my_second_delta',
        name='tictactoe_player',
        executable='tictactoe_player'
    )

    inverse_kinematics_srv_node = Node(
        package='my_second_delta',
        name='inverse_kinematics_server',
        executable='inverse_kinematics_server'
    )

    joint_publisher_node = Node(
        package='my_second_delta',
        name='joint_publisher',
        executable='joint_publisher'
    )

    teleop_keyboard_node = Node(
        package='my_second_delta',
        name='teleop_keyboard',
        executable='teleop_keyboard'
    )

    # Delay rviz start after `joint_state_broadcaster`
    delay_rviz_after_joint_state_broadcaster_spawner = RegisterEventHandler(
        event_handler=OnProcessExit(
            target_action=joint_state_broadcaster_spawner,
            on_exit=[rviz2_node],
        )
    )

    # Delay start of robot_controller after `joint_state_broadcaster`
    delay_robot_controller_spawner_after_joint_state_broadcaster_spawner = RegisterEventHandler(
        event_handler=OnProcessExit(
            target_action=joint_state_broadcaster_spawner,
            on_exit=[robot_controller_spawner],
        )
    )

    delay_copy_delta_nodes_after_robot_controller_spawner = RegisterEventHandler(
        event_handler=OnProcessExit(
            target_action=robot_controller_spawner,
            on_exit=[joint_publisher_node, plc_reader_writer_node
                     , tictactoe_player_node
                     , teleop_keyboard_node
                     ]
        )
    )

    nodes = [
        gazebo_ros_node,
        # control_node,
        robot_state_pub_node,
        joint_state_broadcaster_spawner,
        # delay_rviz_after_joint_state_broadcaster_spawner,
        delay_robot_controller_spawner_after_joint_state_broadcaster_spawner,
        delay_copy_delta_nodes_after_robot_controller_spawner,
        inverse_kinematics_srv_node,
    ]
    return LaunchDescription(declared_arguments +[
        SetEnvironmentVariable(
            'GAZEBO_MODEL_PATH', '/home/sanmaster/onshape-to-robot-tutorial/delta_robot_min_ws/install/my_second_delta/share/my_second_delta/meshes:${GAZEBO_MODEL_PATH}'
        ),
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource([os.path.join(
                get_package_share_directory('gazebo_ros'), 'launch', 'gazebo.launch.py')]),
                launch_arguments={'world': world_arg}.items(),
            )
    ] + nodes)