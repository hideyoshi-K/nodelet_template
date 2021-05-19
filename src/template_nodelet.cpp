#include "template_nodelet.hpp"
#include <pluginlib/class_list_macros.h>

nodelet_template::TemplateNodelet::TemplateNodelet()
{
}

nodelet_template::TemplateNodelet::~TemplateNodelet()
{
}

void nodelet_template::TemplateNodelet::onInit()
{
    m_nh = getPrivateNodeHandle();

    m_pub = m_nh.advertise<std_msgs::String>("send_message", 10);
    m_sub = m_nh.subscribe("recv_message", 10, &nodelet_template::TemplateNodelet::subscribeCallback, this);
    
    m_timer = m_nh.createTimer(ros::Duration(0.1), &nodelet_template::TemplateNodelet::publishCallback, this);
}

void nodelet_template::TemplateNodelet::publishCallback(const ros::TimerEvent& event)
{
    NODELET_INFO("Publish");

    // create message
    std_msgs::String msg;
    m_nh.getParam("pub_message", msg.data);

    // publish
    m_pub.publish(msg);
}

void nodelet_template::TemplateNodelet::subscribeCallback(const std_msgs::StringConstPtr& msg)
{
    NODELET_INFO("Subscribe:%s", msg->data.c_str());
}

PLUGINLIB_EXPORT_CLASS(nodelet_template::TemplateNodelet, nodelet::Nodelet)
