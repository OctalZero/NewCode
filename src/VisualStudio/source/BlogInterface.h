#pragma once
#include <String>
#include <nlohmann/Json.hpp>

class BlogInterface
{
public:
	explicit BlogInterface(const std::string& id);
	virtual ~BlogInterface();

	virtual nlohmann::json getAbstract() = 0;  // 获取博客的概要信息
	std::string getId() const;  // 获取博客id
private:
	std::string time_id_;  // 博客id，博客发布时间作为唯一标识
};

