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
Blog *BlogBroker::FindById(std::string id)
{
    // TODO: 先找缓存中找，如果没找到在数据库中找
    std::string command="select * from Blog where B_id="+id;
    sql::ResultSet* res=RelationalBroker::QueryDatabase(command);
    std::string content,nid,time,title;
    // Loop through and print results
    while (res->next()) {
        id=res->getString(1);
        title=res->getString(2);
        content=res->getString(3);
        time=res->getString(4);
        nid=res->getString(5);
    }

    // 硬编码，后续处理

    Blog *blog=new Blog(id,title,content,time,nid,FindMaterials(id),FindComments(id));

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

// TODO：查询素材（通过博文id）
std::vector<std::string> BlogBroker::FindMaterials(std::string blog_id)
{
    std::vector<std::string> materialIds;
std::string command="select M_id from Material where B_id="+blog_id;
    sql::ResultSet* res=RelationalBroker::QueryDatabase(command);

    std::string materialid;
    while (res->next()) {
        materialid = res->getString(1);
        materialIds.push_back(materialid);
    }
    return materialIds;
}

// TODO: 查询评论（通过博文id）
std::vector<std::string> BlogBroker::FindComments(std::string blog_id)
{
    std::vector<std::string> commentIds;
std::string command="select C_id from Comment where B_id="+blog_id;
    sql::ResultSet* res=RelationalBroker::QueryDatabase(command);

    std::string commentid;
    while (res->next()) {
        commentid = res->getString(1);
        commentIds.push_back(commentid);
    }
    return commentIds;
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
