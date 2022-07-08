#include "Blog.h"
#include <utility>
using json = nlohmann::json;
using std::string;
using std::pair;

Blog::Blog(const std::string &time_id, std::string netizen_id)
    : BlogInterface{time_id}, blogger_{netizen_id}
{

}

Blog::~Blog()
{

}

Blog::Blog(std::string &time_id, std::string title, std::string content, std::string time,
           int scan_nums, int like_nums, std::string netizen_id,std::vector<std::string> materials_id,
           std::vector<std::string> comments_id)
  : BlogInterface{time_id},blogger_{netizen_id}, title_{title}, content_{content}, time_{time},
    scan_nums_{scan_nums}, like_nums_{like_nums}
{
    for(const auto& material : materials_id) {
        materials_.insert(pair<string, MaterialProxy>(material, MaterialProxy(material)));
    }
    for(const auto& comment : comments_id){
        comments_.insert(pair<string, CommentProxy>(comment, CommentProxy(comment)));
    }
}

nlohmann::json Blog::getAbstract()
{
    json blog_abstract;
    blog_abstract["blogger"] = blogger_.getAbstract();
    blog_abstract["title"] = title_;
    blog_abstract["content"] = content_;
    blog_abstract["time"] = time_;
    blog_abstract["scan_nums"] = scan_nums_;
    blog_abstract["like_nums"] = like_nums_;
    for(auto& material : materials_){
        blog_abstract["materials"][material.first] = material.second.getAbstract();
    }

    return blog_abstract;
}

nlohmann::json Blog::getDetail()
{
    json blog_abstract;
    blog_abstract["blogger"] = blogger_.getAbstract();
    blog_abstract["title"] = title_;
    blog_abstract["content"] = content_;
    blog_abstract["time"] = time_;
    blog_abstract["scan_nums"] = scan_nums_;
    blog_abstract["like_nums"] = like_nums_;
    for(auto& material : materials_){
        blog_abstract["materials"][material.first] = material.second.getAbstract();
    }
    for(auto& comment : comments_){
        blog_abstract["comments"][comment.first] = comment.second.getInfo();
    }

    return blog_abstract;
}

const std::string Blog::getTitle() const
{
    return title_;
}

const string Blog::getContent() const
{
    return content_;
}

const string Blog::getTime() const
{
    return time_;
}

int Blog::getScanNums() const
{
    return scan_nums_;
}

int Blog::getLikeNums() const
{
    return like_nums_;
}

const std::vector<string> Blog::getMaterialId() const
{
    std::vector<std::string> materials_id;
    for(const auto &material : materials_){
        materials_id.push_back(material.first);
    }

    return materials_id;
}

const std::vector<string> Blog::getCommentId() const
{
    std::vector<std::string> comments_id;
    for(const auto &comment : comments_){
        comments_id.push_back(comment.first);
    }

    return comments_id;
}
