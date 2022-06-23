#pragma once
#include <String>
#include <nlohmann/Json.hpp>

class NetizenInterface
{
public:
	explicit NetizenInterface(const std::string& id);
	virtual ~NetizenInterface();

	virtual nlohmann::json getAbstract() = 0;  // 获取网民的概要信息
	std::string getId() const;  // 获取网民id
private:
	std::string id_;  // 网民id，系统分配id作为唯一标识
};

