#include "BlogBroker.h"

BlogBroker* BlogBroker::blog_broker_ = nullptr;

BlogBroker *BlogBroker::getInstance()
{
    if(blog_broker_ == nullptr){
        blog_broker_= new BlogBroker();
    }

    return blog_broker_;
}

BlogBroker::~BlogBroker()
{

}
Blog *BlogBroker::FindById(std::string id)
{
    // TODO: 先找缓存中找，如果没找到在数据库中找
    return nullptr;
}

BlogBroker::BlogBroker()
{

}
