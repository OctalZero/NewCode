#include "Netizen.h"
#include "BlogBroker.h"
#include "Blog.h"
#include <iostream>
using json = nlohmann::json;
using std::vector;
using std::string;
using std::pair;

Netizen::Netizen(const string& id)
    : NetizenInterface(id)
{

}

Netizen::Netizen(const string id, string nick_name, vector<string> concerneds_id, vector<string> fans_id, vector<string> blogs_id, vector<string> comments_id)
    : NetizenInterface(id), nick_name_(nick_name)
{
    for (auto &c_id : concerneds_id) {
        concerneds_.insert(pair<string, NetizenProxy>(c_id, NetizenProxy(c_id)));
    }
    for (auto &f_id : fans_id) {
        fans_.insert(pair<std::string, NetizenProxy>(f_id, NetizenProxy(f_id)));
    }
    for (auto &b_id : blogs_id) {
        blogs_.insert(pair<string, BlogProxy>(b_id, BlogProxy(b_id)));
    }
    for (auto &c_id : comments_id) {
        comments_.insert(pair<string, CommentProxy>(c_id, CommentProxy(c_id)));
    }
}

Netizen::~Netizen()
{

}

bool Netizen::PublishBlog(std::string content, std::string time)
{
    vector<string> vec;
    // TODO: 发布笔记

}

nlohmann::json Netizen::getInfo()
{
    json netizen_info;
    netizen_info["name"] = nick_name_;
    // 先取出
    for(auto &concerned : concerneds_) {
        json netizen_abstract = concerned.second.getAbstract();
        netizen_info["concerneds"][concerned.first]["nick_name"] = netizen_abstract["nick_name"];
    }
    for(auto &fan : fans_) {
        json netizen_abstract = fan.second.getAbstract();
        netizen_info["fans"][fan.first]["nick_name"] = netizen_abstract["nick_name"];
    }
    // TODO: blog 信息的获取没处理完
    for(auto &blog : blogs_) {
        json blog_abstract = blog.second.getAbstract();
        netizen_info["blogs"][blog.first]["blogger"] = blog_abstract["blogger"];
        netizen_info["blogs"][blog.first]["title"] = blog_abstract["title"];
        netizen_info["blogs"][blog.first]["content"] = blog_abstract["content"];
        // Q: 材料如何处理
        netizen_info["blogs"][blog.first]["material"] = blog_abstract["material"];
    }

    // Q: 为什么不处理评论
    return netizen_info;
}

nlohmann::json Netizen::ScanBlogs()
{
    std::vector<BlogProxy> BlogProxys=BlogBroker::getInstance()->PushBlogs();
    json blogs;
    for(auto &item:BlogProxys){
        blogs[item.getId()]=item.getAbstract();
    }
    return blogs;
}

nlohmann::json Netizen::CheckBlog(std::string blog_id)
{
    Blog *blog=BlogBroker::getInstance()->FindById(blog_id);
    return blog->getDetail();
}

nlohmann::json Netizen::getAbstract()
{
    json abstract;
    abstract["nick_name"] = nick_name_;

    return abstract;
}

const std::string Netizen::getNickName() const
{
    return nick_name_;
}

const std::vector<std::string> Netizen::getConcerneds() const
{
    vector<string> concerneds;
    for(const auto& concerned : concerneds_) {
        concerneds.push_back(concerned.first);
    }

    return concerneds;
}

const std::vector<string> Netizen::getFans() const
{
    vector<string> fans;
    for(const auto& fan : fans_) {
        fans.push_back(fan.first);
    }

    return fans;
}


