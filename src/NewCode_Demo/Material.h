#ifndef MATERIAL_H
#define MATERIAL_H
#include "MaterialInterface.h"

class Material:public MaterialInterface
{
public:
    explicit Material(const std::string &timeId);
    virtual ~Material(){}

    virtual std::string getAbstract() override;

private:
    // 地址
};

#endif // MATERIAL_H
