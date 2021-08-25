#include"sensor_reader.h"

void velocity_message_recieved(const nav_msgs::Odometry& msg){
    geometry_msgs::Vector3 velocity_message = msg.twist.twist.linear;
    double velocity_magnitude = calculate_velocity_magnitude(velocity_message);
    ROS_INFO("%.3f",velocity_magnitude);
}

double calculate_velocity_magnitude(geometry_msgs::Vector3 velocity_vector){
    double x_square = velocity_vector.x * velocity_vector.x;
    double y_square = velocity_vector.y * velocity_vector.y;
    double z_square = velocity_vector.z * velocity_vector.z;

    return sqrt(x_square + y_square + z_square);
}

int main(int argc, char** argv){
    ros::init(argc, argv, "sensor_reader");

    ros::NodeHandle subscriber_handler;
    ros::Subscriber subscriber = subscriber_handler.subscribe("/base_pose_ground_truth", 1000, &velocity_message_recieved);

    ros::spin();
}