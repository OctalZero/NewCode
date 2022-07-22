#include "BlogBroker.h"
#include "Blog.h"
#include "BlogProxy.h"
#include <iostream>
BlogBroker* BlogBroker::blog_broker_ = nullptr;

BlogBroker *BlogBroker::getInstance()
{
    if(blog_broker_ == nullptr){
        blog_broker_= new BlogBroker();
    }

    return blog_broker_;
}

BlogBroker::~BlogBroker()
{

}

json BlogBroker::InDatabase(std::string id)
{
    json blogJson;

    // 查询Blog表
    std::string command="select * from Blog where B_id="+id;
    sql::ResultSet* result=RelationalBroker::QueryDatabase(command);
    std::string B_name,B_content,B_time,N_id;
    // Loop through and print results
    while (result->next()) {
        B_name=result->getString(2);
        B_content=result->getString(3);
        B_time=result->getString(4);
        N_id=result->getString(5);
    }
    blogJson["B_id"] = id;
    blogJson["B_name"] = B_name;
    blogJson["B_content"] = B_content;
    blogJson["B_time"] = B_time;
    blogJson["N_id"] = N_id;

    // 查询博文的Material
    std::vector<std::string> materialIds;
    command="select M_id from Material where B_id="+id;
    result=RelationalBroker::QueryDatabase(command);

    while (result->next()) {
        materialIds.push_back(std::string(result->getString(1)));
    }
    blogJson["materialIds"] = materialIds;

    // 查询评论（通过博文id）
    std::vector<std::string> commentIds;
    command="select C_id from Comment where B_id="+id;
    result=RelationalBroker::QueryDatabase(command);

    while (result->next()) {
        commentIds.push_back(std::string(result->getString(1)));
    }
    blogJson["commentIds"] = commentIds;

    return blogJson;
}
Blog *BlogBroker::FindById(std::string id)
{
    json blogJson;
    // TODO:现在缓存中找，如果没找到再在数据库中找
    blogJson = InDatabase(id);

    Blog *blog=new Blog(id,blogJson["B_name"],blogJson["B_content"],blogJson["B_time"],blogJson["N_id"],blogJson["materialIds"],blogJson["commentIds"]);

    return blog;
}

std::vector<BlogProxy> BlogBroker::PushBlogs()
{
    std::string command="select * from Blog";
    sql::ResultSet* result=RelationalBroker::QueryDatabase(command);
    std::vector<BlogProxy> blogs;
     // Loop through and print results
    while (result->next()) {
        blogs.push_back(BlogProxy(std::string(result->getString(1))));
    }
    return blogs;
}

bool BlogBroker::InsertBlog(Blog *blog)
{
    std::string command="insert into Blog (B_id,B_content,B_time,N_id) values('"+blog->getId()+"','"+blog->getContent()+"','"+blog->getTime()+"','"+blog->getNetizenId()+"')";
    std::cout<<command<<std::endl;
    RelationalBroker::InsertDatabase(command);

}
BlogBroker::BlogBroker()
{

}
