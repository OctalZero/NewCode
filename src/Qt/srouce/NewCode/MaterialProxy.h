#ifndef MATERIALPROXY_H
#define MATERIALPROXY_H
#include "MaterialInterface.h"

class Material;
class MaterialProxy : public MaterialInterface
{
public:
    explicit MaterialProxy(const std::string &time_id);
    virtual ~MaterialProxy();

    // 获取素材的抽象
    virtual std::string getAbstract() override;
private:
    Material *material_;
};

#endif // MATERIALPROXY_H
