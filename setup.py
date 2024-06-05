from setuptools import find_packages, setup

package_name = 'my_second_delta'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', ['launch/launch_delta.py']),
        ('share/' + package_name + '/urdf', ['urdf/delta.urdf.xacro', 'urdf/macros.xacro', 'urdf/gazebo_stuff.xacro', 'urdf/delta.urdf']),
        ('share/' + package_name + '/meshes', ['meshes/Base_Fija.stl', 'meshes/Brazo.stl', 'meshes/Base_Movil.stl']),
        ('share/' + package_name + '/data', ['data/coordinates.xlsx']),
        ('share/' + package_name + '/config', ['config/delta_joint_position.yaml']),
        ('include/' + package_name + '/hardware', ['hardware/include/ros2_control_demo_example_3/rrbot_system_multi_interface.hpp','hardware/include/ros2_control_demo_example_3/visibility_control.h']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='sanmaster',
    maintainer_email='s.penunuri@hotmail.com',
    description='Second attempt at simulating a delta robot',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'joint_publisher = my_second_delta.joint_publisher:main',
            'inverse_kinematics_server = my_second_delta.inverse_kinematics_server:main',
            'inverse_kinematics_client = my_second_delta.inverse_kinematics_client:main',
            'plc_reader = my_second_delta.plc_reader:main',
            'spawner = my_second_delta.spawner:main'        
            ],
    },
)
