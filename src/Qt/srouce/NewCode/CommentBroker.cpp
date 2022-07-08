#include "CommentBroker.h"
#include "Comment.h"
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
    std::string command="select * from Comment where c_id="+time_id;
    sql::ResultSet* res=RelationalBroker::QueryDatabase(command);
    std::string id,content,nid,jid;
    // Loop through and print results
    while (res->next()) {
        id=res->getString(1);
        content=res->getString(2);
        nid=res->getString(3);
        jid=res->getString(4);
    }
    //retrieveComment(id)

    // 硬编码
    int likenum = 1;

    Comment *comment=new Comment(id,content,nid,jid,likenum);
    return comment;
}


CommentBroker::CommentBroker()
{

}
