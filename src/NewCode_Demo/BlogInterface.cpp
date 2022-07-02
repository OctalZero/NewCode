#include "BlogInterface.h"

BlogInterface::BlogInterface(const std::string &timeId):TimeId_(timeId)
{

}

std::string BlogInterface::getId() const
{
    return TimeId_;
}
