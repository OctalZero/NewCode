#ifndef NETIZENPROXY_H
#define NETIZENPROXY_H

#include "NetizenInterface.h"
class Netizen;

class NetizenProxy : NetizenInterface
{
public:
    explicit NetizenProxy(const std::string &time_id);
    virtual ~NetizenProxy();

    virtual nlohmann::json getAbstract() override;
private:
    Netizen *Netizen_;
};

#endif // NETIZENPROXY_H
