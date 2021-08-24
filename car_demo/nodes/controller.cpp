#include "controller.h"
/**
 * Problem at callback.
 * Callback is not called.
 * I moved car nothing happened.
 */


static geometry_msgs::Vector3 linear_velocity_of_car;
bool message_recieved=false;

void velocity_callback(const nav_msgs::Odometry::ConstPtr &message){
    linear_velocity_of_car = message->twist.twist.linear;
    message_recieved = true;
    ROS_INFO("callback is called");
}

double calculate_linear_velocity_magnitude(geometry_msgs::Vector3 linear_velocity){
    double x_square = linear_velocity.x*linear_velocity.x;
    double y_square = linear_velocity.y*linear_velocity.y;
    double z_square = linear_velocity.z*linear_velocity.z;
    return sqrt(x_square+y_square+z_square);
}
/*
double calculate_throattle_signal(PID_parameters pid_parameters, PID_History pid_history, double velocity_magnitude){
    double error = DESIRED_SPEED - velocity_magnitude;
    double error_proportional = error;
    pid_history.error_sum += error;
    double error_derrivative = error - pid_history.error_one_timestamp_before;
    pid_history.error_one_timestamp_before = error;
    return (pid_parameters.kp * error) + (pid_parameters.kd * error_derrivative) + (pid_parameters.ki * pid_history.error_sum); 
}
*/
int main(int argc, char** argv){
    ros::init(argc, argv, "controller_node");

    // PID_parameters pid_parameters = {0.5, 0, 0};
    // PID_History PID_history = {0 ,0};

    // ros::NodeHandle publisher_handler;
    ros::NodeHandle subscriber_handler;

    // ros::Publisher publisher = publisher_handler.advertise<prius_msgs::Control>("/prius", 1000);
    ros::Subscriber subscriber = subscriber_handler.subscribe("base_pose_ground_truth", 1000, velocity_callback);

    // prius_msgs::Control controller_message;

    double velocity_magnitude;

    while(ros::ok()){
        if(message_recieved){
            velocity_magnitude = calculate_linear_velocity_magnitude(linear_velocity_of_car);
            // controller_message.throttle = calculate_throattle_signal(pid_parameters,PID_history,velocity_magnitude);
            // if(controller_message.throttle > 1){
            //     controller_message.throttle = 1;
            // }
            // if(controller_message.throttle < 0){
            //     controller_message.brake = -controller_message.throttle;
            //     controller_message.throttle = 0;
            //     controller_message.brake /= 2;
            // }

            // controller_message.steer = 0;
            // controller_message.shift_gears = prius_msgs::Control::NO_COMMAND;

            // publisher.publish(controller_message);
            message_recieved = false;
            ROS_INFO("%.3f\n",velocity_magnitude);
        }
    }

}