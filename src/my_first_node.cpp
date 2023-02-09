#include <ros/ros.h>

int main(int argc, char **argv) {
	ros::init(argc, argv, "my_first_node");
	ros::NodeHandle nh;

	ROS_INFO("Hello from my first node");
	ROS_WARN("This is a warning");
	ROS_ERROR("This is an error");
	ROS_INFO("Waiting 10 seconds");
	sleep(10);
	ROS_INFO("End of program");

	return 0;
}