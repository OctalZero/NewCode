#include "NetizenProxy.h"
#include "Netizen.h"
#include "NetizenBroker.h"
NetizenProxy::NetizenProxy(const std::string &time_id):
    NetizenInterface(time_id),Netizen_(nullptr)
{

}

nlohmann::json NetizenProxy::getAbstract()
{
    if(Netizen_==nullptr){
        Netizen_=NetizenBroker::getInstance()->findById(getId());
    }
    return Netizen_->getAbstract();
}
