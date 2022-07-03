#ifndef BLOGSOCIALCONTROL_H
#define BLOGSOCIALCONTROL_H

#include <nlohmann/json.hpp>

class BlogSocialControl
{
    BlogSocialControl();
    ~BlogSocialControl();

    // TODO:登录
    nlohmann::json Login(std::string netizen_id);

    // TODO:推送博文
    nlohmann::json PushBlogs(std::string netizen_id);

    // TODO:查看博文
    nlohmann::json CheckBlog(std::string netizen_id,std::string blog_id);

    // TODO:评论
    bool Comment(std::string netizen_id, std::string blog_id, std::string content);

};

#endif // BLOGSOCIALCONTROL_H
