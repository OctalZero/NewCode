#ifndef COMMENTINTERFACE_H
#define COMMENTINTERFACE_H

#include <nlohmann/json.hpp>
#include <string>

class CommentInterface
{
public:
    explicit CommentInterface(const std::string &time_id);
    virtual ~CommentInterface();

    // 获取评论的信息
    virtual nlohmann::json getInfo()=0;

    std::string getId() const;
private:
    std::string time_id_;
};

#endif // COMMENTINTERFACE_H
