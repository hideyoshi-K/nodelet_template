#pragma once

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <nodelet/nodelet.h>

namespace nodelet_template
{
    class TemplateNodelet : public nodelet::Nodelet
    {
    public:
        TemplateNodelet();
        ~TemplateNodelet();

        virtual void onInit();

    private:
        void publishCallback(const ros::TimerEvent& event);
        void subscribeCallback(const std_msgs::StringConstPtr& msg);

    private:
        ros::NodeHandle m_nh;
        ros::Publisher  m_pub;
        ros::Subscriber m_sub;
        ros::Timer      m_timer;
    };
}
