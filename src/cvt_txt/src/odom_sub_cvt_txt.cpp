#include <ros/ros.h>
#include <nav_msgs/Path.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/PoseStamped.h>
#include <fstream>

class OdomLogger
{
private:
    ros::Subscriber path_sub_;
    std::ofstream file_;

public:
    OdomLogger(ros::NodeHandle& nh)
    {
        file_.open("/root/catkin_ws/bag_to_txt/odom_path_log.txt");   

        if (!file_.is_open()) 
        {
            ROS_ERROR("error");
        }

        path_sub_ = nh.subscribe("/odom", 10, &OdomLogger::odomCallback, this); 

    }

    ~OdomLogger()
    {
        if (file_.is_open()) 
        {
            file_.close();
        }
    }


    void odomCallback(const nav_msgs::Odometry::ConstPtr& msg)
    {
        double x = msg->pose.pose.position.x;
        double y = msg->pose.pose.position.y;

        file_ << x << " " << y << "\n";

    }
};

int main(int argc, char** argv)
{
    ros::init(argc, argv, "odom_path_sub_logger");
    ros::NodeHandle nh;
    OdomLogger logger(nh);
    ros::spin();
    return 0;
}
