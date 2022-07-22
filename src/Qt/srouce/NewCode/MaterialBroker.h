#ifndef MATERIALBROKER_H
#define MATERIALBROKER_H

#include "RelationalBroker.h"
#include <nlohmann/json.hpp>

using json = nlohmann::json;
class Material;

class MaterialBroker : public RelationalBroker
{
public:
    // 单例,获取素材代管者
    static MaterialBroker *getInstance();
    virtual ~MaterialBroker();

    // 在数据库中查找
    json InDatabase(std::string id);

    // TODO:查找素材（通过素材选取时间）
    Material *FindById(std::string time_id);

private:
    MaterialBroker();
private:
    static MaterialBroker* material_broker_;  // 素材代管者对象
};

#endif // MATERIALBROKER_H
