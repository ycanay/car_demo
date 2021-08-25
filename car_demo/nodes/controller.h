#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include"ros/ros.h"
#include"prius_msgs/Control.h"
#include"PID.h"
#include"nav_msgs/Odometry.h"
#include"geometry_msgs/Vector3.h"
#include"math.h"

void velocity_message_recieved(const nav_msgs::Odometry& msg);
double calculate_velocity_magnitude(geometry_msgs::Vector3 velocity_vector);

#endif   /*CONTROLLER_H_*/