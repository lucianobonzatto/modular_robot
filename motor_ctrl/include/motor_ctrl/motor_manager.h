#include "ros/ros.h"
#include "motor.h"
#include "geometry_msgs/Twist.h"
#include <tf2_ros/transform_listener.h>
#include <vector>

class motor_manager{
/*----------------------------parametros--------------------------*/
private:
	std::vector<motor*> motors;
	ros::Subscriber cmd_vel;
	std::string central_frame;
	tf2_ros::Buffer tfBuffer;
	tf2_ros::TransformListener tfListener;
	
/*----------------------------metodos--------------------------*/
public:
	motor_manager(ros::NodeHandle* n, std::string central_frame);
	~motor_manager();
	
	void addMotor(int pin_positive, int pin_negative, float max_velocity, std::string motor_frame);
	void velocityCallback(const geometry_msgs::Twist& msg_in);
};
