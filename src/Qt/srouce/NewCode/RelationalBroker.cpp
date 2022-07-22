#include "RelationalBroker.h"
#include <iostream>
#include <string>

RelationalBroker::RelationalBroker()
{
    // 初始化驱动
    sql::Driver* driver = sql::mariadb::get_driver_instance();

    // 配置连接
    sql::SQLString url("jdbc:mariadb://localhost:3306/NewCode");
    sql::Properties properties({{"user", "root"}, {"password", "123456"}});

    // 建立连接
    std::unique_ptr<sql::Connection> conn(driver->connect(url, properties));
    connection_ = std::move(conn);
    InitDatabase();
}

RelationalBroker::~RelationalBroker()
{

}

void RelationalBroker::InitDatabase()
{
    // 表结构
    //Netizen(N_id,N_name)
    //Comment(C_id,C_content,C_time,N_id,B_id)
    //Material(M_id,M_path,B_id)
    //NetizenRelation(NR_author_id,NR_fan_id)
    //Blog(B_id,B_name,B_content,B_time,N_id)

    try {

        //创造表
        //Netizen
        std::unique_ptr<sql::PreparedStatement> stmnt(connection_->prepareStatement("create table Netizen(N_id varchar(30),N_name varchar(20),primary key(N_id))"));
        stmnt->executeQuery();

        //Blog
        std::unique_ptr<sql::PreparedStatement> stmnt2(connection_->prepareStatement("create table Blog(B_id varchar(30),B_name varchar(30),B_content varchar(2000),B_time DATETIME(2),N_id varchar(30),primary key(B_id),foreign key(B_id) references Netizen(N_id))"));
        stmnt2->executeQuery();

        //Material
        std::unique_ptr<sql::PreparedStatement> stmnt3(connection_->prepareStatement("create table Material(M_id varchar(30),M_path varchar(100),B_id varchar(30),primary key(M_id),foreign key(B_id) references Blog(B_id))"));
        stmnt3->executeQuery();

        //Relation
        std::unique_ptr<sql::PreparedStatement> stmnt4(connection_->prepareStatement("create table NetizenRelation(NR_author_id varchar(30),NR_fan_id varchar(30) ,primary key (NR_author_id,NR_fan_id),foreign key(NR_author_id) references Netizen(N_id),foreign key(NR_fan_id) references Netizen(N_id))"));
        stmnt4->executeQuery();

        //Comment
        std::unique_ptr<sql::PreparedStatement> stmnt5(connection_->prepareStatement("create table Comment(C_id varchar(30),C_content varchar(2000),C_time DATETIME(2),N_id varchar(30),B_id varchar(30),primary key(C_id),foreign key(N_id) references Netizen(N_id),foreign key(B_id) references Blog(B_id))"));
        stmnt5->executeQuery();


        // 添加网民信息
        std::unique_ptr<sql::PreparedStatement> stmnt7(connection_->prepareStatement("insert into Netizen (N_id,N_name) values(?,?)"));
        stmnt7->setString(1,"1");
        stmnt7->setString(2,"zxd");
        stmnt7->execute();

        stmnt7->setString(1,"2");
        stmnt7->setString(2,"xfd");
        stmnt7->execute();

        stmnt7->setString(1,"3");
        stmnt7->setString(2,"wzq");
        stmnt7->execute();

        stmnt7->setString(1,"4");
        stmnt7->setString(2,"yzy");
        stmnt7->execute();

        // 添加博客信息
        std::unique_ptr<sql::PreparedStatement> stmnt8(connection_->prepareStatement("insert into Blog (B_id,B_name,B_content,B_time,N_id) values(?,?,?,?,?)"));

        stmnt8->setString(1,"1");
        stmnt8->setString(2,"C++");
        stmnt8->setString(3,"AAAAAAAAA");
        stmnt8->setDateTime(4,"2022-05-22 10:00:01");
        stmnt8->setString(5,"1");
        stmnt8->execute();

        stmnt8->setString(1,"2");
        stmnt8->setString(2,"C");
        stmnt8->setString(3,"BBBBBBBB");
        stmnt8->setDateTime(4,"2022-05-22 10:00:01");
        stmnt8->setString(5,"2");
        stmnt8->execute();

        stmnt8->setString(1,"3");
        stmnt8->setString(2,"Python");
        stmnt8->setString(3,"CCCCCCCCCC");
        stmnt8->setDateTime(4,"2022-05-22 10:00:01");
        stmnt8->setString(5,"3");
        stmnt8->execute();

        stmnt8->setString(1,"4");
        stmnt8->setString(2,"Linux");
        stmnt8->setString(3,"DDDDDDDDD");
        stmnt8->setDateTime(4,"2022-05-22 10:00:01");
        stmnt8->setString(5,"1");
        stmnt8->execute();

        stmnt8->setString(1,"5");
        stmnt8->setString(2,"Qt");
        stmnt8->setString(3,"EEEEEEEEE");
        stmnt8->setDateTime(4,"2022-05-22 10:00:01");
        stmnt8->setString(5,"4");
        stmnt8->execute();

        // 添加材料信息
        std::unique_ptr<sql::PreparedStatement> stmnt6(connection_->prepareStatement("insert into Material (M_id,M_path,B_id) values(?,?,?)"));

        stmnt6->setString(1,"1");
        stmnt6->setString(2,"picturePath1");
        stmnt6->setString(3,"1");
        stmnt6->execute();

        stmnt6->setString(1,"2");
        stmnt6->setString(2,"videoPath1");
        stmnt6->setString(3,"2");
        stmnt6->execute();

        stmnt6->setString(1,"3");
        stmnt6->setString(2,"path2");
        stmnt6->setString(3,"2");
        stmnt6->execute();

        stmnt6->setString(1,"4");
        stmnt6->setString(2,"path3");
        stmnt6->setString(3,"3");
        stmnt6->execute();

        stmnt6->setString(1,"5");
        stmnt6->setString(2,"path4");
        stmnt6->setString(3,"3");
        stmnt6->execute();

        stmnt6->setString(1,"6");
        stmnt6->setString(2,"path5");
        stmnt6->setString(3,"4");
        stmnt6->execute();

        stmnt6->setString(1,"7");
        stmnt6->setString(2,"path6");
        stmnt6->setString(3,"5");
        stmnt6->execute();

        // 添加粉丝及关注
        std::unique_ptr<sql::PreparedStatement> stmnt9(connection_->prepareStatement("insert into NetizenRelation (NR_author_id,NR_fan_id) values(?,?)"));

        stmnt9->setString(1,"1");
        stmnt9->setString(2,"3");
        stmnt9->execute();

        stmnt9->setString(1,"2");
        stmnt9->setString(2,"1");
        stmnt9->execute();

        stmnt9->setString(1,"4");
        stmnt9->setString(2,"1");
        stmnt9->execute();

        // 添加评论信息
        std::unique_ptr<sql::PreparedStatement> stmnt10(connection_->prepareStatement("insert into Comment (C_id,C_content,C_time,N_id,B_id) values(?,?,?,?,?)"));

        stmnt10->setString(1,"1");
        stmnt10->setString(2,"Good!!");
        stmnt10->setDateTime(3,"2022-05-22 10:00:01");
        stmnt10->setString(4,"1");
        stmnt10->setString(5,"1");
        stmnt10->execute();

        stmnt10->setString(1,"2");
        stmnt10->setString(2,"This is a good song!");
        stmnt10->setDateTime(3,"2022-05-22 10:00:01");
        stmnt10->setString(4,"2");
        stmnt10->setString(5,"2");
        stmnt10->execute();
        //std::cout<<"wanc"<<std::endl;
    }catch(sql::SQLException& e){
        std::cerr << e.what() << std::endl;
    }
}

sql::ResultSet* RelationalBroker::QueryDatabase(std::string command)
{
    try {
        // Create a new Statement
        std::unique_ptr<sql::Statement> stmnt(connection_->createStatement());
        // Execute query
        sql::ResultSet *res = stmnt->executeQuery(command);
        return res;

    }catch(sql::SQLException& e){
        std::cerr << "Error selecting tasks: " << e.what() << std::endl;
    }
    return nullptr;
}

void RelationalBroker::InsertDatabase(std::string command)
{
    try {
        std::unique_ptr<sql::PreparedStatement> stmnt(connection_->prepareStatement(command));
        stmnt->executeQuery();
    }
    catch(sql::SQLException& e){
      std::cerr << "Error inserting new task: " << e.what() << std::endl;
   }
}
