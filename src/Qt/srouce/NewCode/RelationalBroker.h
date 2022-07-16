#ifndef RELATIONALBROKER_H
#define RELATIONALBROKER_H

#include <mariadb/conncpp.hpp>

class RelationalBroker
{
public:
    // 与数据库建立连接
    RelationalBroker();
    virtual ~RelationalBroker();

    // 初始化数据库（建表，添加数据）
    void InitDatabase();

    // 数据库查询操作
    sql::ResultSet* QueryDatabase(std::string command);

    // 数据库插入操作
    void InsertDatabase(std::string command);

private:
    std::unique_ptr<sql::Connection> connection_;  // 数据库连接对象
};

#endif // RELATIONALBROKER_H
