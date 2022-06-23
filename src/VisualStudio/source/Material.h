#pragma once
#include "MaterialInterface.h"
class BlogProxy;

class Material : public MaterialInterface
{
public:
	Material(const std::string& time_id, std::string blog_id);
	~Material();

	virtual nlohmann::json getAbstract() override;
private:
	BlogProxy blog_proxy_;  // 博文代理类
};

