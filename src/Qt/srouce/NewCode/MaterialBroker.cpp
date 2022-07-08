#include "MaterialBroker.h"
#include "Material.h"
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


    std::string command="select * from Material where m_id="+time_id;
    sql::ResultSet* res=RelationalBroker::QueryDatabase(command);
    std::string id,path,jId;
    // Loop through and print results
    while (res->next()) {
        id=res->getString(1);
        path=res->getString(2);
        jId=std::to_string(res->getInt(3));
    }
    //retrieveJotting(id)
    Material* material=new Material(id,jId,path);

    return material;

}

MaterialBroker::MaterialBroker()
{

}
