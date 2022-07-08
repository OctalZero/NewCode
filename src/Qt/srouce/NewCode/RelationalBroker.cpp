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
    //InitDatabase();
}

RelationalBroker::~RelationalBroker()
{

}

void RelationalBroker::InitDatabase()
{
    // 表结构
    //Netizen(n_id,n_name)
    //Comment(c_id,c_content,n_id,b_id)
    //Material(m_id,m_path,b_id)
    //Relation(r_id,n_fan_id)
    //Blog(b_id,b_content,b_time,n_id)

    try {

        //创造表
        //Netizen
//        std::unique_ptr<sql::PreparedStatement> stmnt(connection_->prepareStatement("create table Netizen(n_id varchar(30),n_name varchar(20),primary key(n_id))"));
//        stmnt->executeQuery();

//        //Blog
//        std::unique_ptr<sql::PreparedStatement> stmnt2(connection_->prepareStatement("create table Blog(b_id varchar(30),b_content varchar(2000),b_time DATETIME(2),n_id varchar(30),primary key(b_id),foreign key(n_id) references Netizen(n_id))"));
//        stmnt2->executeQuery();

//        //Material
//        std::unique_ptr<sql::PreparedStatement> stmnt3(connection_->prepareStatement("create table Material(m_id varchar(30),m_path varchar(100),b_id varchar(30),primary key(m_id),foreign key(b_id) references Blog(b_id))"));
//        stmnt3->executeQuery();

//        //Relation
//        std::unique_ptr<sql::PreparedStatement> stmnt4(connection_->prepareStatement("create table Relation(r_id varchar(30),n_fan_id varchar(30) ,primary key (r_id,n_fan_id),foreign key(r_id) references Netizen(n_id),foreign key(n_fan_id) references Netizen(n_id))"));
//        stmnt4->executeQuery();

//        //Comment
//        std::unique_ptr<sql::PreparedStatement> stmnt5(connection_->prepareStatement("create table Comment(c_id varchar(30),c_content varchar(2000),n_id varchar(30),b_id varchar(30),primary key(c_id),foreign key(n_id) references Netizen(n_id),foreign key(b_id) references Blog(b_id))"));
//        stmnt5->executeQuery();


//        // 添加网民信息
//        std::unique_ptr<sql::PreparedStatement> stmnt7(connection_->prepareStatement("insert into Netizen (n_id,n_name) values(?,?)"));
//        stmnt7->setString(1,"1");
//        stmnt7->setString(2,"rose");
//        stmnt7->execute();

//        stmnt7->setString(1,"2");
//        stmnt7->setString(2,"Monica");
//        stmnt7->execute();

//        stmnt7->setString(1,"3");
//        stmnt7->setString(2,"Phoebe");
//        stmnt7->execute();

//        stmnt7->setString(1,"4");
//        stmnt7->setString(2,"Joey");
//        stmnt7->execute();

//        // 添加博客信息
//        std::unique_ptr<sql::PreparedStatement> stmnt8(connection_->prepareStatement("insert into Blog (b_id,b_content,b_time,n_id) values(?,?,?,?)"));

//        stmnt8->setString(1,"1");
//        stmnt8->setString(2,"AAAAAAAAAAAAAAAAAA");
//        stmnt8->setDateTime(3,"2022-05-22 10:00:01");
//        stmnt8->setString(4,"1");
//        stmnt8->execute();

//        stmnt8->setString(1,"2");
//        stmnt8->setString(2,"BBBBBBBBBBBBBBBBB");
//        stmnt8->setDateTime(3,"2022-05-22 10:00:02");
//        stmnt8->setString(4,"2");
//        stmnt8->execute();

//        stmnt8->setString(1,"3");
//        stmnt8->setString(2,"CCCCCCCCC "
//                            "CCCCCCCCCCCCC "
//                            "CCCCCCCCCCCCCCCCCC");
//        stmnt8->setDateTime(3,"2022-06-22 10:00:02");
//        stmnt8->setString(4,"1");
//        stmnt8->execute();

//        stmnt8->setString(1,"4");
//        stmnt8->setString(2,"DDDDDDDDDDDDDDD");
//        stmnt8->setDateTime(3,"2022-07-22 10:00:02");
//        stmnt8->setString(4,"2");
//        stmnt8->execute();

//        stmnt8->setString(1,"5");
//        stmnt8->setString(2,"EEEEEEEEEEEEEEEEEEEEE");
//        stmnt8->setDateTime(3,"2022-08-22 10:00:02");
//        stmnt8->setString(4,"3");
//        stmnt8->execute();

//        // 添加材料信息
//        std::unique_ptr<sql::PreparedStatement> stmnt6(connection_->prepareStatement("insert into Material (m_id,m_path,b_id) values(?,?,?)"));

//        stmnt6->setString(1,"1");
//        stmnt6->setString(2,"picturePath1");
//        stmnt6->setString(3,"1");
//        stmnt6->execute();

//        stmnt6->setString(1,"2");
//        stmnt6->setString(2,"videoPath1");
//        stmnt6->setString(3,"2");
//        stmnt6->execute();

//        stmnt6->setString(1,"3");
//        stmnt6->setString(2,"path2");
//        stmnt6->setString(3,"2");
//        stmnt6->execute();

//        stmnt6->setString(1,"4");
//        stmnt6->setString(2,"path3");
//        stmnt6->setString(3,"3");
//        stmnt6->execute();

//        stmnt6->setString(1,"5");
//        stmnt6->setString(2,"path4");
//        stmnt6->setString(3,"3");
//        stmnt6->execute();

//        stmnt6->setString(1,"6");
//        stmnt6->setString(2,"path5");
//        stmnt6->setString(3,"4");
//        stmnt6->execute();

//        stmnt6->setString(1,"7");
//        stmnt6->setString(2,"path6");
//        stmnt6->setString(3,"5");
//        stmnt6->execute();

//        // ？？？
//        std::unique_ptr<sql::PreparedStatement> stmnt9(connection_->prepareStatement("insert into Relation (r_id,n_fan_id) values(?,?)"));

//        stmnt9->setString(1,"1");
//        stmnt9->setString(2,"3");
//        stmnt9->execute();

//        stmnt9->setString(1,"2");
//        stmnt9->setString(2,"1");
//        stmnt9->execute();

//        stmnt9->setString(1,"4");
//        stmnt9->setString(2,"1");
//        stmnt9->execute();

        // 添加评论信息
        std::unique_ptr<sql::PreparedStatement> stmnt10(connection_->prepareStatement("insert into Comment (c_id,c_content,n_id,b_id) values(?,?,?,?)"));

        stmnt10->setString(1,"1");
        stmnt10->setString(2,"Good!!");
        stmnt10->setString(3,"1");
        stmnt10->setString(4,"1");
        stmnt10->execute();

        stmnt10->setString(1,"2");
        stmnt10->setString(2,"This is a good song!");
        stmnt10->setString(3,"2");
        stmnt10->setString(4,"2");
        stmnt10->execute();

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
