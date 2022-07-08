#ifndef COMMENT_H
#define COMMENT_H

#include <unordered_map>
#include <vector>
#include "CommentInterface.h"
#include "BlogProxy.h"
#include "NetizenProxy.h"

class Comment : public CommentInterface
{
public:
    Comment(std::string time_id, std::string content,
            std::string commenter_id, std::string blog_id, int like_nums);
    virtual ~Comment();

    // 获取评论的信息
    virtual nlohmann::json getInfo() override;

    // 获取评论内容
    const std::string getContent() const;

    // 获取评论者id
    const std::string getCommenterId() const;

    // 获取博文id
    const std::string getBlogId() const;

    // 获取点赞量
    int getLikeNums() const;

private:
    NetizenProxy commenter_proxy_;  // 评论者的代理对象
    BlogProxy blog_proxy_;  // 博文的代理对象
    std::string content_;  // 回复的内容
    int like_nums_;  // 点赞量
};

#endif // COMMENT_H
