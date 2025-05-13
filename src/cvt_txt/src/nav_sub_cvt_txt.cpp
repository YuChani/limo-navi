#include <ros/ros.h>
#include <nav_msgs/Path.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/PoseStamped.h>
#include <fstream>

class PathLogger
{
private:
    ros::Subscriber path_sub_;
    std::ofstream file_;

public:
    PathLogger(ros::NodeHandle& nh)
    {
        file_.open("/root/catkin_ws/bag_to_txt/nav_path_log.txt");   //Nav 

        if (!file_.is_open()) 
        {
            ROS_ERROR("error");
        }

        path_sub_ = nh.subscribe("/move_base/NavfnROS/plan", 10, &PathLogger::pathCallback, this);  // Nav

    }

    ~PathLogger()
    {
        if (file_.is_open()) 
        {
            file_.close();
        }
    }

    void pathCallback(const nav_msgs::Path::ConstPtr& msg)
    {
        ROS_INFO("Received a path with %lu poses", msg->poses.size());

        for (const auto& pose : msg->poses)
        {
            double x = pose.pose.position.x;
            double y = pose.pose.position.y;

            file_ << x << " " << y << "\n";
        }

        file_ << "---\n";  // path 끝 구분선
    }

};

int main(int argc, char** argv)
{
    ros::init(argc, argv, "nav_path_sub_logger");
    ros::NodeHandle nh;
    PathLogger logger(nh);
    ros::spin();
    return 0;
}
