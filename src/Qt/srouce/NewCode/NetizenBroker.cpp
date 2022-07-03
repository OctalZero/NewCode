#include "NetizenBroker.h"
#include "Netizen.h"

NetizenBroker* NetizenBroker::netizen_broker_ = nullptr;

NetizenBroker *NetizenBroker::getInstance()
{
    if(netizen_broker_ == nullptr){
        netizen_broker_ = new NetizenBroker();
    }
    return netizen_broker_;
}

Netizen *NetizenBroker::FindById(std::string id)
{
    // TODO: 先找缓存中找，如果没找到在数据库中找
    return nullptr;
}

std::vector<std::string> NetizenBroker::FindConcereds(std::string id)
{

}

std::vector<std::string> NetizenBroker::FindFans(std::string id)
{

}

std::vector<std::string> NetizenBroker::FindBlogs(std::string id)
{

}

std::vector<std::string> NetizenBroker::FindComments(std::string id)
{

}

NetizenBroker::NetizenBroker()
{

}
