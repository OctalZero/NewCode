#ifndef BLOGBROKER_H
#define BLOGBROKER_H

#include "RelationalBroker.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;
class Blog;
class BlogProxy;
class BlogBroker : public RelationalBroker
{
public:
    // 单例，获取博文实体
    static BlogBroker *getInstance();
    virtual ~BlogBroker();

    // 从数据库中查找博文
    json InDatabase(std::string id);

    // TODO: 查询博文(通过time_id)
    Blog *FindById(std::string time_id);

    // 推送博文，根据顺序，挑选最近几个
    std::vector<BlogProxy> PushBlogs();

    // 将博文存入数据库 测试使用
    bool InsertBlog(Blog *blog);

private:
    BlogBroker();
private:
    static BlogBroker* blog_broker_;  // 博文代管者
};

#endif // BLOGBROKER_H
