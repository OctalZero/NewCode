#include "BlogSocialControl.h"
#include "NetizenBroker.h"
#include "Netizen.h"
#include "BlogBroker.h"

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
    Netizen *netizen=NetizenBroker::getInstance()->FindById(netizen_id);
    return netizen->ScanBlogs();
}

nlohmann::json BlogSocialControl::CheckBlog(std::string netizen_id, std::string blog_id)
{
    Netizen *netizen=NetizenBroker::getInstance()->FindById(netizen_id);
    return netizen->CheckBlog(blog_id);
}

bool BlogSocialControl::PublishBlog(std::string title,std::string blog_id,std::string netizen_id,std::string content, std::string time, std::vector<std::string> &materials_ids)
{
    Netizen *netizen=NetizenBroker::getInstance()->FindById(netizen_id);
    return netizen->PublishBlog(title,content,blog_id,time,materials_ids);
}

bool BlogSocialControl::Comment(std::string netizen_id, std::string blog_id, std::string content)
{

}

