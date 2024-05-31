from setuptools import find_packages, setup

package_name = 'my_third_delta'

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
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='sanmaster',
    maintainer_email='s.penunuri@hotmail.com',
    description='TODO: Package description',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
        ],
    },
)
