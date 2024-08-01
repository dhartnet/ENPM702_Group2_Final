from launch import LaunchDescription
from launch_ros.actions import Node
import os
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    
    # Get file path for waypoint_params.yaml
    parameter_file = os.path.join(
        get_package_share_directory('final_project'), 
        'config', 
        'waypoint_params.yaml'
        )
    
    # Create node
    reach_target_node = Node(
        package="final_project",
        executable="reach_target",
        parameters=[parameter_file], #"final_project/config/waypoint_params.yaml"
    )

    # Launch node
    ld = LaunchDescription()
    ld.add_action(reach_target_node)
    return ld