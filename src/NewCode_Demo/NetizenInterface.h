#ifndef NETIZENINTERFACE_H
#define NETIZENINTERFACE_H
#include <iostream>
#include <nlohmann/json.hpp>

class NetizenInterface
{
public:
    explicit NetizenInterface(const std::string &tid);
    virtual ~NetizenInterface(){}

    // 获取信息
    virtual nlohmann::json getAbstract()  = 0;

    // 获取id
    std::string getId() const;
private:
    // 网民Id
    std::string Id_;
};

#endif // NETIZENINTERFACE_H
