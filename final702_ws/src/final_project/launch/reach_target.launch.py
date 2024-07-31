from launch import LaunchDescription
from launch_ros.actions import Node
import os
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    
    parameter_file = os.path.join(
        get_package_share_directory("final_project", "config", "waypoint_params.yaml")
    )
    
    camera_node = Node(
        package="final_project",
        executable="reach_target",
        parameters=[parameter_file],
    )

    ld = LaunchDescription()
    ld.add_action(camera_node)
    return ld