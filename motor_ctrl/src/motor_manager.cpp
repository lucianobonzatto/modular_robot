#include "motor_manager.h"

motor_manager::motor_manager(ros::NodeHandle* n, std::string central_frame):
central_frame(central_frame), tfListener(tfBuffer){
	cmd_vel = n->subscribe("cmd_vel", 1000, &motor_manager::velocityCallback, this);
}

motor_manager::~motor_manager(){
	
}

void motor_manager::addMotor(int pin_positive, int pin_negative, float max_velocity, std::string motor_frame){
	geometry_msgs::TransformStamped transform;
	try {
		transform = tfBuffer.lookupTransform(central_frame, motor_frame, ros::Time(0));
	} catch (tf2::TransformException ex) {
		ROS_WARN("tf error: %s", ex.what());
	}
	
	motor* p = new motor(pin_positive, pin_negative, max_velocity, transform);
	motors.push_back(p);
}

void motor_manager::velocityCallback(const geometry_msgs::Twist& msg_in){
	
}