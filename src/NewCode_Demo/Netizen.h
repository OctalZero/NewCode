#ifndef NETIZEN_H
#define NETIZEN_H
#include "NetizenInterface.h"
#include <nlohmann/json.hpp>

class Netizen:public NetizenInterface
{
public:
    explicit Netizen(const std::string& Id);

    // TODO:获取信息
    nlohmann::json getInfo();

    virtual ~Netizen(){}



    virtual nlohmann::json getAbstract() override;

private:
    // 关注，粉丝，访问量，名字，博文，评论
};

#endif // NETIZEN_H
