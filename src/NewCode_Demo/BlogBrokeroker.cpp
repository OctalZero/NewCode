#include "BlogBroker.h"

BlogBroker* BlogBroker::BlogBroker_=NULL;

BlogBroker *BlogBroker::getInstance()
{
    if(BlogBroker_==nullptr){
        BlogBroker_=new BlogBroker();
    }
    return BlogBroker_;
}

Blog *BlogBroker::findById(std::string id)
{
    // TODO: 先找缓存中找，如果没找到在数据库中找
    return nullptr;
}

BlogBroker::BlogBroker()
{

}
