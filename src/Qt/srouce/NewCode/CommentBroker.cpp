#include "CommentBroker.h"
CommentBroker* CommentBroker::comment_broker_ = nullptr;

CommentBroker *CommentBroker::getInstance()
{
    if(comment_broker_ == nullptr){
        comment_broker_ = new CommentBroker();
    }
    return comment_broker_;
}

CommentBroker::~CommentBroker()
{

}

Comment *CommentBroker::FindById(std::string time_id)
{
    // TODO: 先找缓存中找，如果没找到在数据库中找
}


CommentBroker::CommentBroker()
{

}
