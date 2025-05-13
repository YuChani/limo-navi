#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <nav_msgs/Path.h>
#include <nav_msgs/Odometry.h>

void nav_path_callback(const nav_msgs::Path::ConstPtr& msg)
{
    for(size_t i = 0; i < msg->poses.size(); i++)
    {
        const double pose_x = msg->poses[i].pose.position.x;    //NavfnROS x
        const double pose_y = msg->poses[i].pose.position.y;    //NavfnROS y

        ROS_INFO("x = %.2f / y = %.2f", pose_x, pose_x);
    }
}



int main(int argc, char** argv)
{
    ros::init(argc, argv, "nav_pose_sub");
    ros::NodeHandle nh;
    ros::Subscriber path_sub = nh.subscribe("/move_base/NavfnROS/plan", 10, nav_path_callback); //NavfnROS


    ros::spin();

    return 0;
}