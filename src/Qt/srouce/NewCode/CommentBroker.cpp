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

json CommentBroker::InDatabase(std::string id)
{
    json commentJson;

    std::string command="select * from Comment where C_id="+id;
    sql::ResultSet* res=RelationalBroker::QueryDatabase(command);
    std::string C_id,C_content,C_time,N_id,B_id;
    // Loop through and print results
    while (res->next()) {
        C_id=res->getString(1);
        C_content=res->getString(2);
        C_time = res->getString(3);
        N_id=res->getString(4);
        B_id=res->getString(5);
    }
    commentJson["C_id"] = C_id;
    commentJson["C_content"] = C_content;
    commentJson["C_time"] = C_time;
    commentJson["N_id"] = N_id;
    commentJson["B_id"] = B_id;

    return commentJson;
}

Comment *CommentBroker::FindById(std::string time_id)
{
    json commentJson;
    // TODO: 先找缓存中找，如果没找到在数据库中找

    commentJson = InDatabase(time_id);

    Comment *comment=new                 Comment(commentJson["C_id"],commentJson["C_content"],commentJson["C_content"],commentJson["N_id"],commentJson["B_id"]);

    return comment;
}


CommentBroker::CommentBroker()
{

}
