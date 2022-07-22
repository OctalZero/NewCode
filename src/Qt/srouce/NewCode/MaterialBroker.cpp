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

json MaterialBroker::InDatabase(std::string id)
{
    json materialJson;
    std::string command="select * from Material where M_id="+id;
    sql::ResultSet* result=RelationalBroker::QueryDatabase(command);
    std::string M_id,M_path,B_Id;
    // Loop through and print results
    while (result->next()) {
        M_id=result->getString(1);
        M_path=result->getString(2);
        B_Id=result->getString(3);
    }
    materialJson["M_id"] = M_id;
    materialJson["M_path"] = M_path;
    materialJson["B_Id"] = B_Id;

    return materialJson;
}

Material *MaterialBroker::FindById(std::string time_id)
{
    json materialJson;

    // TODO: 先找缓存中找，如果没找到在数据库中找
    materialJson = InDatabase(time_id);

    Material* material=new Material(materialJson["M_id"],materialJson["B_Id"],materialJson["M_path"]);

    return material;

}

MaterialBroker::MaterialBroker()
{

}
