#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

int main(int argc, char **argv) {
	
	// initialize node and create a NodeHandle instance
	ros::init(argc, argv, "draw_circle_cw");
	ros::NodeHandle nh;
	
	// inform that that the node has been started
	ROS_INFO("draw_circle_cw node has been started");
	
	// create Publisher instance and publish geometry_msgs::Twist messages to turtle1/cmd_vel topic
	ros::Publisher pub_vel_cmd = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 100);
	
	// set the loop to publish at a rate of 15Hz
	ros::Rate loop_rate(15);

	while(ros::ok()) {

		// declare a geometry_msgs::Twist message to be sent via the topic turtle1/cmd_vel
		geometry_msgs::Twist msg_vel_cmd;
		
		// set the message values
		msg_vel_cmd.linear.x = 2.0; // turtle linear velocity in x-axis
		msg_vel_cmd.angular.z = -1.0; // turtle angular velocity around z-axis

		// publish the message
		pub_vel_cmd.publish(msg_vel_cmd);

		// delay until the next message is to be sent
		loop_rate.sleep();
	}
	
	return 0;
}