#ifndef NETIZEN_H
#define NETIZEN_H

#include "NetizenInterface.h"
#include <nlohmann/json.hpp>
#include <unordered_map>
#include <vector>
#include "NetizenProxy.h"
#include "BlogProxy.h"
#include "CommentProxy.h"

class Netizen : public NetizenInterface
{
public:
    explicit Netizen(const std::string& id);
    Netizen(const std::string id, std::string nick_name, std::vector<std::string> concerneds_id, std::vector<std::string> fans_id, std::vector<std::string> blogs_id, std::vector<std::string> comments_id);
    virtual ~Netizen();

    // 发布博文
    bool PublishBlog(std::string title,std::string blog_id,std::string content, std::string time,std::vector<std::string> &materials_ids);

    // 获取网民详细信息 功能一
    nlohmann::json getInfo();

    // 浏览博文 功能二
    nlohmann::json ScanBlogs();

    // 查看博文 功能三
    nlohmann::json CheckBlog(std::string blog_id);

    // 获取网民的抽象
    virtual nlohmann::json getAbstract() override;

    // 获取昵称
    const std::string getNickName() const;

    // 获取关注
    const std::vector<std::string> getConcerneds() const;

    // 获取粉丝
    const std::vector<std::string> getFans() const;

    // 获取博文
    const std::vector<std::string> getBlogs() const;



private:
    std::string nick_name_;  // 昵称
    std::unordered_map<std::string, NetizenProxy> concerneds_;  // 关注的博主
    std::unordered_map<std::string, NetizenProxy> fans_;  // 粉丝
    std::unordered_map<std::string, BlogProxy> blogs_;  // 发布的博文
    std::unordered_map<std::string, BlogProxy> collectblogs_;  // 收藏的博文
    std::unordered_map<std::string, CommentProxy> comments_;  // 发布的评论
};

#endif // NETIZEN_H
