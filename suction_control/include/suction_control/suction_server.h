#include <sstream>

#include "ros/ros.h"
#include "suction_control/Suction.h"
#include "std_msgs/Int8.h"
#include "std_msgs/String.h"

class SuctionCup
{
    public:
        explicit SuctionCup(ros::NodeHandle nh);
        bool publish_cmd(std_msgs::String cmd);
        bool callback(suction_control::Suction::Request &req,
                     suction_control::Suction::Response &res);
        void advertise_srv();
        ros::NodeHandle nh_;
        ros::ServiceServer service;

    private:
        ros::Publisher suction_chatter;


};