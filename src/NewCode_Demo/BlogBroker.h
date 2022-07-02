#ifndef BLOGBROKER_H
#define BLOGBROKER_H
#include "RelationalBroker.h"
class Blog;
class BlogBroker:public RelationalBroker
{
public:
    static BlogBroker *getInstance();

    // TODO:未实现
    Blog *findById(std::string id);


    // TODO: 缓存未实现 清除部分缓存
    void update() override;

    virtual ~BlogBroker();
private:

    BlogBroker();
    static BlogBroker* BlogBroker_;
};

#endif // BLOGBROKER_H
