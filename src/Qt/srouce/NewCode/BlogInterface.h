#ifndef BLOGINTERFACE_H
#define BLOGINTERFACE_H

#include <nlohmann/json.hpp>
#include <string>

class BlogInterface
{
public:
    explicit BlogInterface(const std::string &time_id);
    virtual ~BlogInterface();

    // 获取博文的抽象
    virtual nlohmann::json getAbstract()= 0;

    // 获取博文的详细信息
    virtual nlohmann::json getDetail()= 0;

    // 获取id
    std::string getId() const;

private:
    std::string time_id_;
};

#endif // BLOGINTERFACE_H
