#include "ros/ros.h"
#include "turtlesim/Pose.h"
#include "geometry_msgs/Twist.h"

float turtle_pose_x = 0;
float desired_x_dist;

void pose_callback(const turtlesim::Pose::ConstPtr& pose_msg) {
	turtle_pose_x = pose_msg->x;
	ROS_INFO("turtle_pose_x: [%f]", pose_msg->x);
}

int main(int argc, char **argv) {

	ros::init(argc, argv, "my_turtle_pose_control");
	ros::NodeHandle nh;
	nh.getParam("desired_x_distance_in_m", desired_x_dist);
	
	ROS_INFO("my_turtle_pose_control node has been started");

	ros::Subscriber sub_pose_data = nh.subscribe("/turtle1/pose", 1000, pose_callback);
	ros::Publisher pub_vel_cmd = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 10);
	ros::Rate loop_rate(10);

	while(ros::ok) {
		
		geometry_msgs::Twist msg_vel_cmd;

		if(turtle_pose_x < desired_x_dist) {
			msg_vel_cmd.linear.x = 1.0;
			msg_vel_cmd.angular.z = 0.0;
		}
		else {
			msg_vel_cmd.linear.x = 0.0;
			msg_vel_cmd.angular.z = 0.0;
		}

		ROS_INFO("turtle linear command velocity: [%f]", msg_vel_cmd.linear.x);
		
		pub_vel_cmd.publish(msg_vel_cmd);
		
		ros::spinOnce();
		loop_rate.sleep();
	}

	return 0;
}