#include "BlogProxy.h"
#include "Blog.h"
#include "BlogBroker.h"

BlogProxy::BlogProxy(const std::string& time_id)
	: BlogInterface{ time_id }
{
}

BlogProxy::~BlogProxy()
{
}

nlohmann::json BlogProxy::getAbstract()
{
	if (blog_ == nullptr) {
		// TODO: 1
		blog_ = BlogBroker
	}
	return nlohmann::json();
}
