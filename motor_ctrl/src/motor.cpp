#include "motor.h"

motor::motor(int pin_positive,int pin_negative, float max_velocity, geometry_msgs::TransformStamped transform):
pin_positive(pin_positive), pin_negative(pin_negative), max_velocity(max_velocity), transform(transform){
	
}

motor::~motor(){
	
}

float motor::getMaxVelocity(){return max_velocity;}
geometry_msgs::Transform motor::getTransform(){return transform.transform;}