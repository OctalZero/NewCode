#pragma once
#include <String>
#include <nlohmann/Json.hpp>

class CommentInterface
{
public:
	explicit CommentInterface(const std::string& id);
	virtual ~CommentInterface();

	virtual nlohmann::json getAbstract() = 0;  // 获取评论的概要信息
	std::string getId() const;  // 获取评论id
private:
	std::string time_id_;  // 评论id，评论发布时间唯一标识
};

