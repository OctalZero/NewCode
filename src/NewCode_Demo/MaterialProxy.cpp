#include "MaterialProxy.h"
#include "MaterialBroker.h"
#include "Material.h"

MaterialProxy::MaterialProxy(const std::string &timeId):
    MaterialInterface(timeId),Material_(nullptr)
{
}

MaterialProxy::~MaterialProxy()
{
}


std::string MaterialProxy::getAbstract()
{
    if(Material_==nullptr){

        Material_=MaterialBroker::getInstance()->findById(getId());
    }
     return Material_->getAbstract();
}
