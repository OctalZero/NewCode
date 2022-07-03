#include "CommentProxy.h"
#include "CommentBroker.h"
#include "Comment.h"

CommentProxy::CommentProxy(const std::string &time_id):
    CommentInterface{time_id}, comment_{nullptr}
{

}

CommentProxy::~CommentProxy()
{

}

nlohmann::json CommentProxy::getInfo()
{
    if(comment_ == nullptr){
        comment_ = CommentBroker::getInstance()->FindById(getId());
    }
    return comment_->getInfo();
}
