#include "MaterialBroker.h"

MaterialBroker* MaterialBroker::material_broker_= nullptr;

MaterialBroker *MaterialBroker::getInstance()
{
    if(material_broker_== nullptr){
        material_broker_ = new MaterialBroker();
    }

    return material_broker_;
}

MaterialBroker::~MaterialBroker()
{

}

Material *MaterialBroker::FindById(std::string time_id)
{
    // TODO: 先找缓存中找，如果没找到在数据库中找
}

MaterialBroker::MaterialBroker()
{

}
