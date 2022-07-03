#include "MaterialProxy.h"
#include "MaterialBroker.h"
#include "Material.h"

MaterialProxy::MaterialProxy(const std::string &time_id):
    MaterialInterface{time_id}, material_{nullptr}
{
}

MaterialProxy::~MaterialProxy()
{
}


std::string MaterialProxy::getAbstract()
{
    if(material_ == nullptr){
        material_ = MaterialBroker::getInstance()->FindById(getId());
    }

    return material_->getAbstract();
}
