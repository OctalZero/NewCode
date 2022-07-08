#ifndef NETIZENBROKER_H
#define NETIZENBROKER_H

#include "RelationalBroker.h"
#include <unordered_map>
#include <string>
class Netizen;

class NetizenBroker : public RelationalBroker
{
public:
    // 单例，获取网民代管者
    static NetizenBroker* getInstance();

    // TODO: 查找网民对象(通过网民id)
    Netizen *FindById(std::string id);

    // TODO:查找关注(通过网民id)
    std::vector<std::string> FindConcereds(std::string id);

    // TODO:查找粉丝(通过网民id)
    std::vector<std::string> FindFans(std::string id);

    // TODO:查找发布的博文(通过网民id)
    std::vector<std::string> FindBlogs(std::string id);

    // TODO:查找评论(通过网民id)
    std::vector<std::string> FindComments(std::string id);

//    // TODO: 缓存未实现 更新缓存
//    void UpdateCache() override;

    virtual ~NetizenBroker();
private:
    NetizenBroker();
private:
    static NetizenBroker* netizen_broker_;  // 网民代管者对象
};

#endif // NETIZENBROKER_H
