from setuptools import find_packages, setup

package_name = 'my_first_delta'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', ['launch/basic_launch.py']),
        ('share/' + package_name + '/urdf', ['urdf/base.urdf.xacro']),

    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='sanmaster',
    maintainer_email='s.penunuri@hotmail.com',
    description='Simple delta simulation',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'joint_publisher = my_first_delta.joint_publisher:main',
            'inverse_kinematics_server = my_first_delta.inverse_kinematics_server:main',
            'inverse_kinematics_client = my_first_delta.inverse_kinematics_client:main',
            'get_user_input = my_first_delta.get_user_input:main',
            'excel_publisher = my_first_delta.excel_publisher:main',
        ],
    },
)
