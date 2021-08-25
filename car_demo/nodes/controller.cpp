#include "controller.h"
/**
 * @brief Main publisher node.
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */

static double velocity_magnitude;

void velocity_message_recieved(const nav_msgs::Odometry& msg){
    geometry_msgs::Vector3 velocity_message = msg.twist.twist.linear;
    velocity_magnitude = calculate_velocity_magnitude(velocity_message);
}

double calculate_velocity_magnitude(geometry_msgs::Vector3 velocity_vector){
    double x_square = velocity_vector.x * velocity_vector.x;
    double y_square = velocity_vector.y * velocity_vector.y;
    double z_square = velocity_vector.z * velocity_vector.z;

    return sqrt(x_square + y_square + z_square);
}


int main(int argc, char** argv){
    ros::init(argc, argv, "controller_node");

    ros::NodeHandle publisher_handler;
    ros::Publisher publisher = publisher_handler.advertise<prius_msgs::Control>("/prius", 1000);

    ros::NodeHandle subscriber_handler;
    ros::Subscriber subscriber = subscriber_handler.subscribe("/base_pose_ground_truth",1000,&velocity_message_recieved);

    ros::Rate rate(100);
    PID pid_controller(5,1,0.05,15);
    pid_controller.set_control_input_limits(1,-1);

    prius_msgs::Control controller_message;
    while(ros::ok()){
        double control_input = pid_controller.get_control_input(velocity_magnitude);
        ROS_INFO("%.3f",velocity_magnitude);
        if(control_input >= 0){
            ROS_INFO("throattle %.3f",control_input);
            controller_message.throttle = control_input;
            controller_message.brake = 0;
        }
        else{
            ROS_INFO("brake %.3f",control_input);
            controller_message.throttle = 0;
            controller_message.brake = -control_input;
        }
        controller_message.steer = 0;
        controller_message.shift_gears = prius_msgs::Control::FORWARD;
        publisher.publish(controller_message);

        ros::spinOnce();

        rate.sleep();
    }
    return 0;
}