#ifndef NETIZENBROKER_H
#define NETIZENBROKER_H

#include "RelationalBroker.h"
#include <unordered_map>
#include <string>
#include <nlohmann/json.hpp>

class Netizen;
using json = nlohmann::json;

class NetizenBroker : public RelationalBroker
{
public:
    // 单例，获取网民代管者
    static NetizenBroker* getInstance();

    // 在数据库中查找
    json InDataBase(std::string id);

    // TODO: 查找网民对象(通过网民id)
    Netizen *FindById(std::string id);

    virtual ~NetizenBroker();
private:
    NetizenBroker();
private:
    static NetizenBroker* netizen_broker_;  // 网民代管者对象
};

#endif // NETIZENBROKER_H
