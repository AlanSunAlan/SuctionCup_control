#include "suction_control/suction_server.h"
#define POWER_ON 1
#define POWER_OFF 0
#define SUCTION_IN 2
#define SUCTION_STILL 3
#define SUCTION_OUT 4

SuctionCup::SuctionCup(ros::NodeHandle nh){
    this->nh_ = nh;
    this->suction_chatter = nh.advertise<std_msgs::Int8>("suction_control", 100);
}

bool SuctionCup::publish_cmd(std_msgs::String cmd){
    std_msgs::Int8 cmd_num;
    if(cmd.data == "power_on"){
        cmd_num.data = POWER_ON;
        this->suction_chatter.publish(cmd_num);
        ROS_INFO("***The power of suction cup is on.***");
        return true;
    }else if(cmd.data == "power_off"){
        cmd_num.data = POWER_OFF;
        this->suction_chatter.publish(cmd_num);
        ROS_INFO("***The power of suction cup is off.***");
        return true;
    }else if(cmd.data == "suction_in"){
        cmd_num.data = SUCTION_IN;
        this->suction_chatter.publish(cmd_num);
        ROS_INFO("***Suction cup is attaching objects.***");
        return true;
    }else if(cmd.data == "suction_still"){
        cmd_num.data = SUCTION_STILL;
        this->suction_chatter.publish(cmd_num);
        ROS_INFO("***Suction cup is at rest.***");
        return true;
    }else if(cmd.data == "suction_out"){
        cmd_num.data = SUCTION_OUT;
        this->suction_chatter.publish(cmd_num);
        ROS_INFO("***Suction cup is detaching objects.***");
        return true;
    }else{
        cmd_num.data = POWER_OFF;
        this->suction_chatter.publish(cmd_num);
        return false;
    }
}

bool SuctionCup::callback(suction_control::Suction::Request &req,
                     suction_control::Suction::Response &res)
{   
    //this->SuctionCup::publish_cmd(req.cmd_string.data);
    std_msgs::String str;
    str.data = req.cmd_string;
    res.result = this->SuctionCup::publish_cmd(str);
    return res.result;
    //return res.result;
}

void SuctionCup::advertise_srv(){
        this->service = this->nh_.advertiseService("suction_control_service", &SuctionCup::callback, this);
}

int main(int argc, char **argv){
    ros::init(argc, argv, "suction_server");
    ros::NodeHandle nh;
    
    SuctionCup sc(nh);
    sc.advertise_srv();

    ROS_INFO("Service for suction cup ready to take action.");
    ROS_INFO("Request command available: power_on, power_off, suction_in, suction_still, suction_out");

    ros::spin();

    return 0;
}