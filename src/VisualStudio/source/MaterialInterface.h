#pragma once
#include <String>
#include <nlohmann/Json.hpp>

class MaterialInterface
{
public:
	explicit MaterialInterface(const std::string& id);
	virtual ~MaterialInterface();

	virtual nlohmann::json getAbstract() = 0;  // 获取素材的概要信息
	std::string getId() const;  // 获取素材id
private:
	std::string time_id_;  // 素材id，素材添加时间作为唯一标识
};

