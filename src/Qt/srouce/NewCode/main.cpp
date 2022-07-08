#include <QCoreApplication>
#include "BlogSocialControl.h"
#include <iostream>
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


    return a.exec();
}
