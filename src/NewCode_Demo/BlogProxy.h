#ifndef BLOGPROXY_H
#define BLOGPROXY_H
#include <nlohmann/json.hpp>
#include "BlogInterface.h"
class Blog;

class BlogProxy:public BlogInterface
{
public:
    explicit BlogProxy(const std::string &timeId);
    virtual ~BlogProxy();
    virtual nlohmann::json getAbstract() override;
    virtual nlohmann::json getDetail() override;

private:
    Blog* Blog_;
};

#endif // BLOGPROXY_H
