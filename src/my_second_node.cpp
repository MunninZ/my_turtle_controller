#include "ros/ros.h"

int main(int argc, char **argv) {
	ros::init(argc, argv, "my_second_node");
	ros::NodeHandle nh;

	ROS_INFO("My second node has been started");
	
	ros::Rate loop_rate(10);

	while(ros::ok) {
		ROS_INFO("I am in the loop");
		loop_rate.sleep();
	}
	
	return 0;
}