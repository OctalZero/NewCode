#ifndef BLOGBROKER_H
#define BLOGBROKER_H

#include "RelationalBroker.h"
class Blog;

class BlogBroker : public RelationalBroker
{
public:
    // 单例，获取博文实体
    static BlogBroker *getInstance();
    virtual ~BlogBroker();

    // TODO: 查询博文(通过time_id)
    Blog *FindById(std::string time_id);

    // TODO：查询素材（通过博文id）
    std::vector<std::string> FindMaterials(std::string blog_id);

    // TODO: 查询评论（通过博文id）
    std::vector<std::string> FindComments(std::string blog_id);

    // TODO：查询点赞数（通过博文id）
    int FindLikeNums(std::string blog_id);

    // TODO: 查询浏览数
    int FindScanNums(std::string blog_id);


//    // TODO: 缓存未实现 更新缓存
//    void UpdateCache() override;
private:
    BlogBroker();
private:
    static BlogBroker* blog_broker_;  // 博文代管者
};

#endif // BLOGBROKER_H
