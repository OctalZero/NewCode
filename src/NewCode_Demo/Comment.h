#ifndef COMMENT_H
#define COMMENT_H
#include "CommentInterface.h"

class Comment:public CommentInterface
{
public:
    explicit Comment(const std::string &timeId);

    virtual ~Comment(){}

    virtual nlohmann::json getInfo() override;


private:
    // 时间，内容，回复人
};

#endif // COMMENT_H
