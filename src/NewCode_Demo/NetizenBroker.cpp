#include "NetizenBroker.h"
#include "Netizen.h"

NetizenBroker* NetizenBroker::NetizenBroker_ = NULL;

NetizenBroker *NetizenBroker::getInstance()
{
    if(NetizenBroker_==nullptr){
        NetizenBroker_=new NetizenBroker();
    }
    return NetizenBroker_;
}

Netizen *NetizenBroker::findById(std::string id)
{
    // TODO: 先找缓存中找，如果没找到在数据库中找
    return nullptr;
}
NetizenBroker::NetizenBroker()
{

}
