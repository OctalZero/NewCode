#include "CommentBroker.h"
CommentBroker* CommentBroker::CommentBroker_=NULL;

CommentBroker *CommentBroker::getInstance()
{
    if(CommentBroker_==nullptr){
        CommentBroker_=new CommentBroker();
    }
    return CommentBroker_;
}

Comment *CommentBroker::findById(std::string id)
{
    // TODO: 先找缓存中找，如果没找到在数据库中找

    return nullptr;
}


void CommentBroker::update()
{

}

CommentBroker::CommentBroker()
{

}
