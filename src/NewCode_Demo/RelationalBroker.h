#ifndef RELATIONALBROKER_H
#define RELATIONALBROKER_H
#include <mariadb/conncpp.hpp>

class RelationalBroker
{
public:
    // 与数据库建立连接
    RelationalBroker();

    // 初始化数据库（建表，添加数据）
    void initDataBase();

    // 数据库查询操作
    sql::ResultSet* query(std::string command);

    // 数据库插入操作
    void insert(std::string command);

    // 清除某些缓存 子类实现
    virtual void update()=0;

    virtual ~RelationalBroker(){}

private:
    std::unique_ptr<sql::Connection> Connection_;
};

#endif // RELATIONALBROKER_H
