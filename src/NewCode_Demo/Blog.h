#ifndef BLOG_H
#define BLOG_H
#include "BlogInterface.h"
#include "NetizenProxy.h"

class Blog:public BlogInterface
{
public:
    explicit Blog(const std::string &timeId);
    virtual ~Blog(){}

    virtual nlohmann::json getAbstract() override;
    virtual nlohmann::json getDetail() override;

private:
    // 题目，图片，作者名，阅读量，评论
};

#endif // BLOG_H
