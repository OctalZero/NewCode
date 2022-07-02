#ifndef COMMENTPROXY_H
#define COMMENTPROXY_H
#include "CommentInterface.h"

class Comment;
class CommentProxy:public CommentInterface
{
public:
    explicit CommentProxy(const std::string &timeId);
    virtual ~CommentProxy();
    virtual nlohmann::json getInfo() override;

private:
    Comment* Comment_;
};

#endif // COMMENTPROXY_H
