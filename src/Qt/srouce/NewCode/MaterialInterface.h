#ifndef MATERIALINTERFACE_H
#define MATERIALINTERFACE_H

#include <string>

class MaterialInterface
{
public:
    explicit MaterialInterface(const std::string &time_id);
    virtual ~MaterialInterface();

    // 获取素材的抽象
    virtual std::string getAbstract()  = 0;

    // 获取素材的id
    const std::string getId() const;
private:
    std::string time_id_;  // 素材的唯一标识，以素材添加的时间作为id
};

#endif // MATERIALINTERFACE_H
