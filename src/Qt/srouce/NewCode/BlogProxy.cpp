#include "BlogProxy.h"
#include "Blog.h"
#include "BlogBroker.h"

BlogProxy::BlogProxy(const std::string &time_id):
    BlogInterface{time_id}, blog_{nullptr}
{

}

BlogProxy::~BlogProxy()
{

}

nlohmann::json BlogProxy::getAbstract()
{
    if(blog_ == nullptr){
        blog_ = BlogBroker::getInstance()->FindById(getId());
    }
    return blog_->getAbstract();
}

nlohmann::json BlogProxy::getDetail()
{
    if(blog_ == nullptr){
        blog_ = BlogBroker::getInstance()->FindById(getId());
    }
    return blog_->getDetail();
}
