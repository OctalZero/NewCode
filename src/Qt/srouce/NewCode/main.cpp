#include <QCoreApplication>
#include "BlogSocialControl.h"
#include "RelationalBroker.h"
#include "NetizenBroker.h"
#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    BlogSocialControl control;


    std::cout<<"登陆："<<std::endl;
    std::cout<< control.Login("1").dump(4)<<std::endl;
    std::cout<<"推送博文："<<std::endl;
    std::cout<< control.PushBlogs("1").dump(4)<<std::endl;
    std::cout<<"查看博文 1"<<std::endl;
    std::cout<< control.CheckBlog("1","1").dump(4)<<std::endl;

//    std::cout<<"创建博文"<<std::endl;
//    std::vector<std::string> materials_ids{"123","456","789"};
//    if(control.PublishBlog("C++","11","1","反转链表","2022-05-22 10:00:01",materials_ids))cout<<"创建博文成功"<<endl;

//    std::cout<<"查看博文 11"<<std::endl;
//    std::cout<< control.CheckBlog("1","11").dump(4)<<std::endl;

    return a.exec();
}
