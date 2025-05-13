#include <ros/ros.h>
#include <nav_msgs/Path.h>
#include <fstream>

class PathToCSV
{
private:
    ros::Subscriber path_sub_;
    std::ofstream file_;

public:
    PathToCSV(ros::NodeHandle& nh)
    {
        // CSV 파일 열기
        file_.open("/root/catkin_ws/bag_to_txt/csv_path_log.csv");
        if (!file_.is_open())
        {
            ROS_ERROR("CSV error.");
        }
        else
        {
            // CSV 헤더 작성
            file_ << "x,y\n";
        }

        path_sub_ = nh.subscribe("/move_base/NavfnROS/plan", 10, &PathToCSV::pathCallback, this);
    }

    ~PathToCSV()
    {
        if (file_.is_open())
            file_.close();
    }

    void pathCallback(const nav_msgs::Path::ConstPtr& msg)
    {
        for (const auto& pose : msg->poses)
        {
            const double x = pose.pose.position.x;
            const double y = pose.pose.position.y;
            file_ << x << "," << y << "\n";
        }

        ROS_INFO("complete (%lu points)", msg->poses.size());
    }
};

int main(int argc, char** argv)
{
    ros::init(argc, argv, "path_to_csv_node");
    ros::NodeHandle nh;

    PathToCSV logger(nh);

    ros::spin();
    return 0;
}
