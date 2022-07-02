#ifndef NETIZENBROKER_H
#define NETIZENBROKER_H

#include "RelationalBroker.h"

class Netizen;

class NetizenBroker:public RelationalBroker
{
public:
    static NetizenBroker* getInstance();

    // TODO:未实现
    Netizen *findById(std::string id);

    // TODO: 缓存未实现 清除部分缓存
    void update() override;

    virtual ~NetizenBroker();
private:
    NetizenBroker();

    static NetizenBroker *NetizenBroker_;
};

#endif // NETIZENBROKER_H
