#include "Comment.h"

using json = nlohmann::json;

Comment::Comment(const std::string time_id, std::string content,
        std::string commenter_id, std::string blog_id, int like_nums)
    : CommentInterface{time_id}, commenter_proxy_(commenter_id),
      blog_proxy_{blog_id}, content_ {content}, like_nums_{like_nums}
{

}

Comment::~Comment()
{

}

nlohmann::json Comment::getInfo()
{
    json comment_info;
    comment_info["content"] = content_;
    comment_info["commenter"] = commenter_proxy_.getAbstract();
    comment_info["like_nums"] = like_nums_;

    return comment_info;
}

const std::string Comment::getContent() const
{
    return content_;
}

const std::string Comment::getCommenterId() const
{
    return commenter_proxy_.getId();
}

const std::string Comment::getBlogId() const
{
    return blog_proxy_.getId();
}

int Comment::getLikeNums() const
{
    return like_nums_;
}




