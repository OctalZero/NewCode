#pragma once
#include <String>
#include "BlogInterface.h"
class Blog;

class BlogProxy : public BlogInterface
{
public:
	explicit BlogProxy(const std::string& time_id);
	virtual ~BlogProxy();

	virtual nlohmann::json getAbstract() override;
private:
	Blog* blog_ = nullptr;  // 博文实体类
};

