#include "RelationalBroker.h"
#include <iostream>
#include <string>

RelationalBroker::RelationalBroker()
{
    // Instantiate Driver
    sql::Driver* driver = sql::mariadb::get_driver_instance();

    // Configure Connection
    sql::SQLString url("jdbc:mariadb://localhost:3306/NewCode");
    sql::Properties properties({{"user", "root"}, {"password", "123456"}});

    // Establish Connection
    std::unique_ptr<sql::Connection> conn(driver->connect(url, properties));
    Connection_=std::move(conn);
    initDataBase();
}

void RelationalBroker::initDataBase()
{
    // 表结构
    //Netizen(N_id,N_Name)
    //Comment(C_id,C_content,N_id,B_id)
    //Material(M_id,M_path,B_id)
    //Relation(R_id,N_Fan_id)
    //Blog(B_id,B_content,B_time,N_id)

    try {

        //创造表
        //Netizen
        std::unique_ptr<sql::PreparedStatement> stmnt(Connection_->prepareStatement("create table if not exists Netizen(N_id INT(30) unsigned AUTO_INCREMENT,N_Name varchar(20) not null,primary key(N_id))"));
        stmnt->executeQuery();

        //Blog
        std::unique_ptr<sql::PreparedStatement> stmnt2(Connection_->prepareStatement("create table if not exists Blog (B_id INT(30) unsigned NOT NULL ,B_content varchar(2000) not null,B_time DATETIME(2) not null ,N_id INT(30) unsigned not null,primary key(B_id),foreign key(N_id) references Netizen(N_id) on delete cascade on update cascade)"));
        stmnt2->executeQuery();

        //Material
        std::unique_ptr<sql::PreparedStatement> stmnt3(Connection_->prepareStatement("create table if not exists Material (M_id INT(30) unsigned NOT NULL ,M_path varchar(100) not null,B_id INT(30) unsigned not null,primary key(M_id),foreign key(B_id) references Blog(B_id) on delete cascade on update cascade)"));
        stmnt3->executeQuery();

        //Relation
        std::unique_ptr<sql::PreparedStatement> stmnt4(Connection_->prepareStatement("create table if not exists Relation (R_id INT(30) unsigned NOT NULL,N_Fan_id INT(30) unsigned NOT NULL,primary key (R_id,N_Fan_id),foreign key(R_id) references Netizen(N_id) on delete cascade on update cascade,foreign key(N_Fan_id) references Netizen(N_id) on delete cascade on update cascade)"));
        stmnt4->executeQuery();

        //Comment
        std::unique_ptr<sql::PreparedStatement> stmnt5(Connection_->prepareStatement("create table if not exists Comment (C_id INT(30) unsigned NOT NULL,C_content varchar(2000) not null ,N_id INT(30) unsigned not null,B_id INT(30) unsigned not null,primary key(C_id),foreign key(N_id) references Netizen(N_id) on delete cascade on update cascade,foreign key(B_id) references Blog(B_id) on delete cascade on update cascade)"));
        stmnt5->executeQuery();


        // 添加网民信息
        std::unique_ptr<sql::PreparedStatement> stmnt7(Connection_->prepareStatement("insert into Netizen (N_id,N_Name) values(?,?)"));
        stmnt7->setInt(1,1);
        stmnt7->setString(2,"rose");
        stmnt7->execute();

        stmnt7->setInt(1,2);
        stmnt7->setString(2,"Monica");
        stmnt7->execute();

        stmnt7->setInt(1,3);
        stmnt7->setString(2,"Phoebe");
        stmnt7->execute();

        stmnt7->setInt(1,4);
        stmnt7->setString(2,"Joey");
        stmnt7->execute();

        // 添加博客信息
        std::unique_ptr<sql::PreparedStatement> stmnt8(Connection_->prepareStatement("insert into Blog (B_id,B_content,B_time,N_id) values(?,?,?,?)"));

        stmnt8->setInt(1,1);
        stmnt8->setString(2,"AAAAAAAAAAAAAAAAAA");
        stmnt8->setDateTime(3,"2022-05-22 10:00:01");
        stmnt8->setInt(4,1);
        stmnt8->execute();

        stmnt8->setInt(1,2);
        stmnt8->setString(2,"BBBBBBBBBBBBBBBBB");
        stmnt8->setDateTime(3,"2022-05-22 10:00:02");
        stmnt8->setInt(4,2);
        stmnt8->execute();

        stmnt8->setInt(1,3);
        stmnt8->setString(2,"CCCCCCCCC "
                            "CCCCCCCCCCCCC "
                            "CCCCCCCCCCCCCCCCCC");
        stmnt8->setDateTime(3,"2022-06-22 10:00:02");
        stmnt8->setInt(4,1);
        stmnt8->execute();

        stmnt8->setInt(1,4);
        stmnt8->setString(2,"DDDDDDDDDDDDDDD");
        stmnt8->setDateTime(3,"2022-07-22 10:00:02");
        stmnt8->setInt(4,2);
        stmnt8->execute();

        stmnt8->setInt(1,5);
        stmnt8->setString(2,"EEEEEEEEEEEEEEEEEEEEE");
        stmnt8->setDateTime(3,"2022-08-22 10:00:02");
        stmnt8->setInt(4,3);
        stmnt8->execute();

        // 添加材料信息
        std::unique_ptr<sql::PreparedStatement> stmnt6(Connection_->prepareStatement("insert into Material (M_id,M_path,B_id) values(?,?,?)"));

        stmnt6->setInt(1,1);
        stmnt6->setString(2,"picturePath1");
        stmnt6->setInt(3,1);
        stmnt6->execute();

        stmnt6->setInt(1,2);
        stmnt6->setString(2,"videoPath1");
        stmnt6->setInt(3,2);
        stmnt6->execute();

        stmnt6->setInt(1,3);
        stmnt6->setString(2,"path2");
        stmnt6->setInt(3,2);
        stmnt6->execute();

        stmnt6->setInt(1,4);
        stmnt6->setString(2,"path3");
        stmnt6->setInt(3,3);
        stmnt6->execute();

        stmnt6->setInt(1,5);
        stmnt6->setString(2,"path4");
        stmnt6->setInt(3,3);
        stmnt6->execute();

        stmnt6->setInt(1,6);
        stmnt6->setString(2,"path5");
        stmnt6->setInt(3,4);
        stmnt6->execute();

        stmnt6->setInt(1,7);
        stmnt6->setString(2,"path6");
        stmnt6->setInt(3,5);
        stmnt6->execute();

        // ？？？
        std::unique_ptr<sql::PreparedStatement> stmnt9(Connection_->prepareStatement("insert into Relation (R_id,N_Fan_id) values(?,?)"));

        stmnt9->setInt(1,1);
        stmnt9->setInt(2,3);
        stmnt9->execute();

        stmnt9->setInt(1,2);
        stmnt9->setInt(2,1);
        stmnt9->execute();

        stmnt9->setInt(1,4);
        stmnt9->setInt(2,1);
        stmnt9->execute();

        // 添加评论信息
        std::unique_ptr<sql::PreparedStatement> stmnt10(Connection_->prepareStatement("insert into Comment (C_id,C_content,N_id,B_id) values(?,?,?,?)"));

        stmnt10->setInt(1,1);
        stmnt10->setString(2,"Good!!");
        stmnt10->setInt(3,1);
        stmnt10->setInt(4,1);
        stmnt10->execute();

        stmnt10->setInt(1,2);
        stmnt10->setString(2,"This is a good song!");
        stmnt10->setInt(3,2);
        stmnt10->setInt(4,2);
        stmnt10->execute();

    }catch(sql::SQLException& e){
        std::cerr<< e.what() << std::endl;
    }
}

// 数据库查询操作
sql::ResultSet* RelationalBroker::query(std::string command)
{
    try {
        // Create a new Statement
        std::unique_ptr<sql::Statement> stmnt(Connection_->createStatement());
        // Execute query
        sql::ResultSet *res = stmnt->executeQuery(command);
        return res;

    }catch(sql::SQLException& e){
        std::cerr << "Error selecting tasks: " << e.what() << std::endl;
    }
    return nullptr;
}

// 数据库插入操作
void RelationalBroker::insert(std::string command)
{
    try {
        std::unique_ptr<sql::PreparedStatement> stmnt(Connection_->prepareStatement(command));
        stmnt->executeQuery();
    }
    catch(sql::SQLException& e){
      std::cerr << "Error inserting new task: " << e.what() << std::endl;
   }
}
