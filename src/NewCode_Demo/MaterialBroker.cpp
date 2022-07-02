#include "MaterialBroker.h"

MaterialBroker* MaterialBroker::MaterialBroker_=NULL;

MaterialBroker *MaterialBroker::getInstance()
{
    if(MaterialBroker_==nullptr){
        MaterialBroker_=new MaterialBroker();
    }
    return MaterialBroker_;
}

Material *MaterialBroker::findById(std::string id)
{
    // TODO: 先找缓存中找，如果没找到在数据库中找
    return nullptr;
}
MaterialBroker::MaterialBroker()
{

}
