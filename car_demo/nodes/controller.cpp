#include "controller.h"
/**
 * @brief Main publisher node.
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */

int main(int argc, char** argv){
    ros::init(argc, argv, "controller_node");

    ros::NodeHandle publisher_handler;
    ros::Publisher publisher = publisher_handler.advertise<prius_msgs::Control>("/prius", 1000);

    prius_msgs::Control controller_message;
    ros::Rate rate(5);

    prius_msgs::Control controller_message;
    while(ros::ok()){
        controller_message.brake = 0;
        controller_message.steer = 0;
        controller_message.throttle = 0.05;
        controller_message.shift_gears = prius_msgs::Control::FORWARD;
        publisher.publish(controller_message);
        rate.sleep();
    }
    return 0;
}