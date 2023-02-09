#include "ros/ros.h"
#include "turtlesim/Pose.h"

void pose_callback(const turtlesim::Pose::ConstPtr& pose_msg) {

    ROS_INFO("x:[%f], y:[%f], theta:[%f]", pose_msg-> x, pose_msg-> y, pose_msg-> theta);
    ROS_INFO("v:[%f], w:[%f]", pose_msg-> linear_velocity, pose_msg-> angular_velocity);

}

int main(int argc, char **argv) {

    ros::init(argc, argv, "my_turtle_pose_subscriber");
    ros::NodeHandle nh;
    ROS_INFO("my_turtle_pose_subscriber node has been started");
    ros::Subscriber sub_pose_data = nh.subscribe("/turtle1/pose", 1000, pose_callback);
    ros::spin();

    return 0;

}