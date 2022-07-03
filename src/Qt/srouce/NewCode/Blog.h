#ifndef BLOG_H
#define BLOG_H

#include <unordered_map>
#include <vector>
#include "BlogInterface.h"
#include "NetizenProxy.h"
#include "MaterialProxy.h"
#include "CommentProxy.h"

class Blog : public BlogInterface
{
public:
    Blog(const std::string &time_id, std::string netizen_id);
    Blog(const std::string &time_id, std::string title, std::string content, std::string time,
         int scan_nums, int like_nums, std::vector<std::string> materials_id,
         std::vector<std::string> comments_id);
    virtual ~Blog();

    // Q:沒弄懂这个抽象的数据需要哪些
    // 获取博文的抽象
    virtual nlohmann::json getAbstract() override;

    // 获取博文的详细信息
    virtual nlohmann::json getDetail() override;

    // 获取标题
    const std::string getTitle() const;

    // 获取内容
    const std::string getContent() const;

    // 获取时间
    const std::string getTime() const;

    // 获取浏览量
    int getScanNums() const;

    // 获取点赞量
    int getLikeNums() const;

    // 获取素材列表的所有素材id
    const std::vector<std::string> getMaterialId() const;

    // 获取评论列表的所有评论id
    const std::vector<std::string> getCommentId() const;
private:
    NetizenProxy blogger_; // 博主
    std::string title_;  // 题目
    std::string content_;  // 内容
    std::string time_;  // 时间
    int scan_nums_;  // 浏览量
    int like_nums_;  // 点赞量
    std::unordered_map<std::string, MaterialProxy> materials_;  // 素材列表
    std::unordered_map<std::string, CommentProxy> comments_;  // 评论列表
};

#endif // BLOG_H
