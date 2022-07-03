#ifndef BLOGPROXY_H
#define BLOGPROXY_H

#include "BlogInterface.h"
class Blog;

class BlogProxy : public BlogInterface
{
public:
    explicit BlogProxy(const std::string &time_id);
    virtual ~BlogProxy();

    // 获取博文的抽象
    virtual nlohmann::json getAbstract() override;

    // 获取博文的详细信息
    virtual nlohmann::json getDetail() override;

private:
    Blog* blog_;  // 博文对象
};

#endif // BLOGPROXY_H
