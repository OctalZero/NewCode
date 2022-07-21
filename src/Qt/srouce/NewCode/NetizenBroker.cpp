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


NetizenBroker::~NetizenBroker()
{

}

Netizen *NetizenBroker::FindById(std::string id)
{
    // TODO: 先找缓存中找，如果没找到在数据库中找
    // 数据库中找，然后实例化 Netizen

    // Future: 未处理查询不到的情况
    std::string command = "select * from Netizen where N_id=" + id;
    std::string nickName;
    sql::ResultSet* result = RelationalBroker::QueryDatabase(command);
    // 返回结果
    while (result->next())
    {
        nickName = result->getString(2);
    }

    Netizen *netizen = new Netizen(id, nickName, FindConcereds(id), FindFans(id),FindBlogs(id), FindComments(id));
    return netizen;
}

std::vector<std::string> NetizenBroker::FindConcereds(std::string id)
{
    std::string command="select NR_author_id from NetizenRelation where NR_fan_id="+id;
    std::vector<std::string> conceredIds;
    sql::ResultSet* res=RelationalBroker::QueryDatabase(command);

    while (res->next()) {
        conceredIds.push_back(std::string(res->getString(1)));
    }
    return conceredIds;
}

std::vector<std::string> NetizenBroker::FindFans(std::string id)
{
    std::string command="select NR_fan_id from NetizenRelation where NR_author_id="+id;
    std::vector<std::string> fansIds;
    sql::ResultSet* res=RelationalBroker::QueryDatabase(command);

    while (res->next()) {
        fansIds.push_back(std::string(res->getString(1)));
    }
    return fansIds;
}

std::vector<std::string> NetizenBroker::FindBlogs(std::string id)
{
    std::string command = "select B_id from Blog where N_id="+id;
    sql::ResultSet* result = RelationalBroker::QueryDatabase(command);
    std::vector<std::string> blog_ids;

    while (result->next()) {
        blog_ids.push_back(std::string(result->getString(1)));
    }
    return blog_ids;
}

std::vector<std::string> NetizenBroker::FindComments(std::string id)
{
    std::string command="select C_id from Comment where B_id="+id;
    std::vector<std::string> commentIds;
    sql::ResultSet* res=RelationalBroker::QueryDatabase(command);

    while (res->next()) {       
        commentIds.push_back(std::string(res->getString(1)));
    }
    return commentIds;
}

NetizenBroker::NetizenBroker()
{

}
