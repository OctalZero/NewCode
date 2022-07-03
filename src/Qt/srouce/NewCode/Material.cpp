#include "Material.h"

Material::Material(const std::string &time_id, std::string blog_id)
    : MaterialInterface{time_id}, blog_proxy_{blog_id}
{

}
Material::Material(const std::string &time_id, std::string blog_id, std::string path)
    : MaterialInterface{time_id}, blog_proxy_{blog_id}, path_{path}
{

}

Material::~Material()
{

}

std::string Material::getAbstract()
{
    return getPath();
}

const std::string Material::getBlogId() const
{
    return blog_proxy_.getId();
}

const std::string Material::getPath() const
{
    return path_;
}
