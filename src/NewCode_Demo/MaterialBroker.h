#ifndef MATERIALBROKER_H
#define MATERIALBROKER_H
#include "RelationalBroker.h"
class Material;
class MaterialBroker:public RelationalBroker
{
public:
    static MaterialBroker *getInstance();

    // TODO:未实现
    Material *findById(std::string id);

    // TODO: 缓存未实现 清除部分缓存
    void update() override;

    virtual ~MaterialBroker();
private:
    MaterialBroker();
    static MaterialBroker* MaterialBroker_;

};

#endif // MATERIALBROKER_H
