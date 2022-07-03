#ifndef MATERIAL_H
#define MATERIAL_H

#include "MaterialInterface.h"
#include "BlogProxy.h"

class Material : public MaterialInterface
{
public:
    // 没有添加素材的情况
    Material(const std::string &time_id, std::string blog_id);
    // 添加了素材的情况
    Material(const std::string &time_id, std::string blog_id, std::string path);
    virtual ~Material();

    // 获取素材的抽象
    virtual std::string getAbstract() override;

    // 获取博文的id
    const std::string getBlogId() const;

    // 获取素材的地址
    const std::string getPath() const;

private:
    BlogProxy blog_proxy_;  // 博文代理对象
    std::string path_;  // 素材的地址
};

#endif // MATERIAL_H
