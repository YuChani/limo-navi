#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <nav_msgs/Path.h>
#include <nav_msgs/Odometry.h>


void odom_path_callback(const nav_msgs::Odometry::ConstPtr& msg)
{

    const double pose_x = msg->pose.pose.position.x;    
    const double pose_y = msg->pose.pose.position.y;    

    ROS_INFO("x = %.2f / y = %.2f", pose_x, pose_x);
}


int main(int argc, char** argv)
{
    ros::init(argc, argv, "odom_pose_sub");
    ros::NodeHandle nh;

    ros::Subscriber path_sub = nh.subscribe("/odom", 10, odom_path_callback);  //odom

    ros::spin();

    return 0;
}