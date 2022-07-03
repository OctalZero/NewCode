#ifndef COMMENTBROKER_H
#define COMMENTBROKER_H

#include "RelationalBroker.h"
class Comment;

class CommentBroker : public RelationalBroker
{
public:
    // 单例,获取评论代管者
    static CommentBroker *getInstance();
    virtual ~CommentBroker();

    // TODO:查找评论（通过评论发布时间）:
    Comment *FindById(std::string time_id);

    //    // TODO: 缓存未实现 更新缓存
    //    void UpdateCache() override;

private:
    CommentBroker();
private:
    static CommentBroker* comment_broker_;
};

#endif // COMMENTBROKER_H
