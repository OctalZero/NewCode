#include "Material.h"
#include "BlogProxy.h"

Material::Material(const std::string& time_id, std::string blog_id)
	: MaterialInterface{ time_id }, blog_proxy_{ blog_id }
{
	// TODO: 0
}

