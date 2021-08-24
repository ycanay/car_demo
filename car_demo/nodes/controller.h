#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include"ros/ros.h"
#include"prius_msgs/Control.h"
#include"sensor_msgs/LaserScan.h"
#include"nav_msgs/Odometry.h"
#include"geometry_msgs/Vector3.h"
#include"math.h"

#define DESIRED_SPEED 3

struct PID_parameters {
    float   kp ;
    float   kd ;
    float   ki ;
};

struct PID_History {
    float   error_one_timestamp_before;
    float   error_sum;
};

#endif   /*CONTROLLER_H_*/