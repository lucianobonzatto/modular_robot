#include <string>
#include "geometry_msgs/TransformStamped.h"
#include "geometry_msgs/Transform.h"

class motor{
/*----------------------------parametros--------------------------*/
private:
	int pin_positive, pin_negative;
	float max_velocity;
	geometry_msgs::TransformStamped transform;

/*----------------------------metodos--------------------------*/
public:
	motor(int pin_positive, int pin_negative, float max_velocity, geometry_msgs::TransformStamped transform);
	~motor();
	float getMaxVelocity();
	geometry_msgs::Transform getTransform();
};
