#include "CommentProxy.h"
#include "CommentBroker.h"
#include "Comment.h"
CommentProxy::CommentProxy(const std::string &timeId):
    CommentInterface(timeId),Comment_(nullptr)
{

}

CommentProxy::~CommentProxy()
{

}

nlohmann::json CommentProxy::getInfo()
{
    if(Comment_ == nullptr){
        Comment_ = CommentBroker::getInstance()->findById(getId());
    }
    return Comment_->getInfo();
}
