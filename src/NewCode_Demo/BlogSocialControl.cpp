#include "BlogSocialControl.h"
#include "NetizenBroker.h"
#include "Netizen.h"
BlogSocialControl::BlogSocialControl()
{

}

BlogSocialControl::~BlogSocialControl()
{

}

nlohmann::json BlogSocialControl::login(std::string netizenId)
{
    Netizen *netizen=NetizenBroker::getInstance()->findById(netizenId);
    // TODO:填写日志、读取日志
    //netizen->writeLog();
    //netizen->readLog();
    return netizen->getInfo();
}
