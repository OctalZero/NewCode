#ifndef MATERIALPROXY_H
#define MATERIALPROXY_H
#include "MaterialInterface.h"

class Material;
class MaterialProxy:public MaterialInterface
{
public:
    explicit MaterialProxy(const std::string &timeId);
    virtual ~MaterialProxy();
    virtual std::string getAbstract() override;

private:
    Material *Material_;
};

#endif // MATERIALPROXY_H
