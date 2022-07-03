#ifndef NETIZENINTERFACE_H
#define NETIZENINTERFACE_H

#include <nlohmann/json.hpp>
#include <string>

class NetizenInterface
{
public:
    explicit NetizenInterface(const std::string &id);
    virtual ~NetizenInterface();

    // 获取网民的抽象
    virtual nlohmann::json getAbstract()  = 0;

    // 获取id
    std::string getId() const;
private:
    std::string id_;  // 网民的id
};

#endif // NETIZENINTERFACE_H
