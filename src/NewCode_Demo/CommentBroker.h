#ifndef COMMENTBROKER_H
#define COMMENTBROKER_H

#include "RelationalBroker.h"
class Comment;
class CommentBroker:public RelationalBroker
{
public:
    static CommentBroker *getInstance();

    // TODO:未实现
    Comment *findById(std::string id);

    // TODO: 缓存未实现 清除部分缓存
    void update() override;

    virtual ~CommentBroker();
private:
    CommentBroker();
    static CommentBroker* CommentBroker_;
};

#endif // COMMENTBROKER_H
