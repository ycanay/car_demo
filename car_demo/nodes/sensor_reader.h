#ifndef SENSOR_READER_H_
#define SENSOR_READER_H_

#include"ros/ros.h"
#include"nav_msgs/Odometry.h"
#include"geometry_msgs/Vector3.h"
#include"math.h"

#define DESIRED_SPEED 3

void velocity_message_recieved(const nav_msgs::Odometry& msg);
double calculate_velocity_magnitude(geometry_msgs::Vector3 velocity_vector);

#endif   /*SENSOR_READER_H_*/