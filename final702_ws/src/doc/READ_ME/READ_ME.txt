Group 2 - ENPM702 Final Project Submission

To run this code... 

- Unzip the src folder into your workspace.

- Navigate to your worlspace location in the terminal window

- Properly source your workspace and "colcon build"

- Run the following command in your terminal

      "ros2 launch final_package final_package.launch.py"

      - Gazebo will open and spawn the robot, cameras, and objects

- In a second terminal running simultaneously to the first terminal, navigate to the workspace and source it 

- In the second terminal, run the following command

      "ros2 launch final_package reach_target.launch.py"

      - The robot will begin recieving data and commands for motion


Unfortunately, we are having complications getting the waypoint_params.yaml file to properly feed into the code.
We are consistently getting the following error, and after three days of troubleshooting have not found the solution...

[ERROR] [reach_target-1]: process has died [pid 304439, exit code -11, cmd '/home/dustinhartnett/Documents/GitHub/ENPM702_Group2_Final/
final702_ws/install/final_project/lib/final_project/reach_target --ros-args --params-file /home/dustinhartnett/Documents/GitHub/ENPM702_Group2_Final/
final702_ws/install/final_project/share/final_project/config/waypoint_params.yaml'].

Other than this issue, the aspects of the program required to command the robot's movement seem to work properly, as expected.

We really appreciate all the support you provided while we worked through this project. It was a very challenging assignment, but was very entertaining to test
our abilities after a great semester. Thank you again for a great semester and lot's of help along the way! Enjoy the rest of your summer!