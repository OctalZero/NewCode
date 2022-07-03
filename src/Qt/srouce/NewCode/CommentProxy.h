#ifndef COMMENTPROXY_H
#define COMMENTPROXY_H

#include "CommentInterface.h"
class Comment;

class CommentProxy : public CommentInterface
{
public:
    explicit CommentProxy(const std::string &time_id);
    virtual ~CommentProxy();

    // 获取评论的信息
    virtual nlohmann::json getInfo() override;
private:
    Comment* comment_;
};

#endif // COMMENTPROXY_H
