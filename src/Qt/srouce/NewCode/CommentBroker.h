#ifndef COMMENTBROKER_H
#define COMMENTBROKER_H

#include "RelationalBroker.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;
class Comment;

class CommentBroker : public RelationalBroker
{
public:
    // 单例,获取评论代管者
    static CommentBroker *getInstance();
    virtual ~CommentBroker();

    // 在数据库中查找
    json InDatabase(std::string id);

    // TODO:查找评论（通过评论发布时间）:
    Comment *FindById(std::string time_id);

private:
    CommentBroker();
private:
    static CommentBroker* comment_broker_;
};

#endif // COMMENTBROKER_H
