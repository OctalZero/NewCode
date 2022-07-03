#include "BlogSocialControl.h"
#include "NetizenBroker.h"
#include "Netizen.h"
BlogSocialControl::BlogSocialControl()
{

}

BlogSocialControl::~BlogSocialControl()
{

}

nlohmann::json BlogSocialControl::Login(std::string netizen_id)
{
    Netizen *netizen = NetizenBroker::getInstance()->FindById(netizen_id);
    // TODO:填写日志、读取日志
    //netizen->writeLog();
    //netizen->readLog();
    return netizen->getInfo();
}

nlohmann::json BlogSocialControl::PushBlogs(std::string netizen_id)
{

}

nlohmann::json BlogSocialControl::CheckBlog(std::string netizen_id, std::string blog_id)
{

}

bool BlogSocialControl::Comment(std::string netizen_id, std::string blog_id, std::string content)
{

}

