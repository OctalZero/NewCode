#include "NetizenBroker.h"
#include "Netizen.h"
#include <iostream>

NetizenBroker* NetizenBroker::netizen_broker_ = nullptr;

NetizenBroker *NetizenBroker::getInstance()
{
    if(netizen_broker_ == nullptr){
        netizen_broker_ = new NetizenBroker();
    }
    return netizen_broker_;
}

json NetizenBroker::InDataBase(std::string id)
{
    json netizenJson;
    // 查询Netizen表
    std::string command = "select * from Netizen where N_id="+id;
    std::string N_name;
    sql::ResultSet* result = RelationalBroker::QueryDatabase(command);
    // 返回结果
    while (result->next())
    {
        N_name = result->getString(2);
    }
    netizenJson["N_id"]=id;
    netizenJson["N_name"]=N_name;

    // 查找网民的关注
    command = "select NR_author_id from NetizenRelation where NR_fan_id="+id;
    std::vector<std::string> conceredIds;
    result=RelationalBroker::QueryDatabase(command);

    while (result->next()) {
        conceredIds.push_back(std::string(result->getString(1)));
    }
    netizenJson["conceredIds"] = conceredIds;

    // 查找粉丝
    command="select NR_fan_id from NetizenRelation where NR_author_id="+id;
    std::vector<std::string> fansIds;
    result=RelationalBroker::QueryDatabase(command);

    while (result->next()) {
        fansIds.push_back(std::string(result->getString(1)));
    }
    netizenJson["fansIds"] = fansIds;

    // 查找博客
    command = "select B_id from Blog where N_id="+id;
    result = RelationalBroker::QueryDatabase(command);
    std::vector<std::string> blogIds;

    while (result->next()) {
        blogIds.push_back(std::string(result->getString(1)));
    }
    netizenJson["blogIds"] = blogIds;

    // 查找评论
    command="select C_id from Comment where B_id="+id;
    std::vector<std::string> commentIds;
    result=RelationalBroker::QueryDatabase(command);

    while (result->next()) {
        commentIds.push_back(std::string(result->getString(1)));
    }
    netizenJson["commentIds"] = commentIds;

    return netizenJson;
}


NetizenBroker::~NetizenBroker()
{

}

Netizen *NetizenBroker::FindById(std::string id)
{
    json netizenJson;
    // TODO: 先在缓存中找，如果没找到再在数据库中找

    netizenJson = InDataBase(id);

    Netizen *netizen = new Netizen(id, netizenJson["N_name"], netizenJson["conceredIds"], netizenJson["fansIds"],netizenJson["blogIds"], netizenJson["commentIds"]);

    return netizen;
}

NetizenBroker::NetizenBroker()
{

}
