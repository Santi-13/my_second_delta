# **Delta Arm Simulation ROS2 package**
With this package, you can create a digital twin of a delta robot simulated in Gazebo. It also works as the processor unit for the decision making process when playing a game of tic tac toe.

## How does it work? 
The twin is rendered in gazebo through a urdf .xacro file, which is then converted to the proper file type for Gazebo to render. To overcome the limitation of gazebo of simulating parallel robots, a process similar to the one andy-Chien used for [his delta simulation](https://github.com/andy-Chien/simple_delta_robot/tree/main) was implemented, though it was needed to update the ros control library to the newer ros2 control library. 

The position of the end actuator is received through a TCP connection with a Siemens PLC (using the snap7 library) among other data, a node within the package (plc_reader_writer.py) reads the end effector position of the physical delta robot, with which an inverse kinematics service can be called which returns the proper angle for each arm to reach the end position. Bidirectional communication is available in which a remote operator can control the physical robot by using WASD commands for x and y movement, as well as QE for z-movements.

## Robot Description
As mentioned before, the robot's description (its links and joints) is simulated using a .xacro file; this, so the description of the robot can be easily achieved using diverse macros and property tags. Some links have visual meshes (seen on the meshes folder), so the robot reassembles the physical version. A simulated world, as well as a tic tac toe board was also simulated. Click each link to find more about [urdf](https://docs.ros.org/en/jazzy/Tutorials/Intermediate/URDF/URDF-Main.html), [xacro](https://wiki.ros.org/xacro), and [sdf](http://sdformat.org/tutorials) files.

<p float="left" align="center">
  <img src="https://github.com/Santi-13/my_second_delta/assets/61756465/b78eaca6-bf1b-4d72-9f3f-4bc736d88059" width="350"/>
  <img src="https://github.com/Santi-13/my_second_delta/assets/61756465/b5154c92-94b8-4eed-bd64-0133c242247a" width="400"/>
</p>

## Communication and Control of the robot
As previously mentioned, the simulation communicates with the physical robot by using the snap7 library, which facilitates communication with Siemens PLCs. Among other data, a node reads the x, y, and z coordinates of the end effector, while a teleoperated keyboard node is responsible to writing to a PLC variable whenever a movement is requested by pressing any of the previously mentioned keys. 

The robot is controlled in Gazebo using the ros2 control library. First, a gazebo tag was needed to invoke the gazebo_ros2_control plugin, as well as to invoke the definition of the controller managers using a .yaml file. Then, within a ros2_control tag, multiple types of controller were defined for each of the relevant joints ***(position, velocity and torque controllers)***; and the generic gazebo_ros2_control/GazeboSystem plugin was used in the hardware definition. It is important to note that, because of the parallel nature of the robot, the robot cannot be controlled using conventional position or velocity controllers. The control was made by applying a proportional controller to each arm, in which a torque would be applied to each until the desired angle was achieved. This is reported in the terminal when launching the project.

`[joint_publisher]: Rotating arm1: 0.072593 rad | arm2: 0.072593 rad | arm3: 0.072593 rad`

The complete ros2 graph of the project is as follows:

![image](https://github.com/Santi-13/my_second_delta/assets/61756465/1d392102-0cc3-4283-9c2b-18d1fbe30602)

## Tic Tac Toe
As mentioned and seen on the ROS graph, a tic tac toe node is also initialized with the launch file. This node runs a minimax algorithm to determine the best possible move on a tic tac toe game based on data sent by the PLC, which is previously analyzed from a camera, and sends back the coordinates of the best play to the PLC so the robot executes it. The data sent is: enemy grid position (row and col in a 0-2 format), starting player, start game flag, etc.

While the start game flag is 1, the node waits for any changes reported on the board, and then sends the best possible play back to the PLC.

## Requirements
All library requirements can be found in the package.xml file. Besides that, for this package to work without modifications, it's necessary that the user has:
- A Siemens PLC with an IP address of "192.168.0.1".
- A global DB declared within the PLC where the reading and writing of variables takes place, you must pass the x, y, and z coordinates to this DB.
- A Cognex camera connection to the PLC (just for tic tac toe).

## Contact
For any questions or recommendations, please contact me!
- Email: s.penunuri@hotmail.com
