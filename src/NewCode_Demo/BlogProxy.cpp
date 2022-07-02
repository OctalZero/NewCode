#include "BlogProxy.h"
#include "Blog.h"
#include "BlogBroker.h"
BlogProxy::BlogProxy(const std::string &timeId):
    BlogInterface(timeId),Blog_(nullptr)
{

}

BlogProxy::~BlogProxy()
{

}

nlohmann::json BlogProxy::getAbstract()
{
    if(Blog_ == nullptr){
        Blog_ = BlogBroker::getInstance()->findById(getId());
    }
    return Blog_->getAbstract();
}

nlohmann::json BlogProxy::getDetail()
{
    if(Blog_ == nullptr){
        Blog_ = BlogBroker::getInstance()->findById(getId());
    }
    return Blog_->getDetail();
}
