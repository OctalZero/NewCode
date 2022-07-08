#include "NetizenProxy.h"
#include "Netizen.h"
#include "NetizenBroker.h"

NetizenProxy::NetizenProxy(const std::string &time_id)
    :NetizenInterface{time_id}, netizen_{nullptr}
{

}

NetizenProxy::~NetizenProxy()
{

}

nlohmann::json NetizenProxy::getAbstract()
{
    if(netizen_ == nullptr){
        netizen_ = NetizenBroker::getInstance()->FindById(getId());
    }
    return netizen_->getAbstract();
}
