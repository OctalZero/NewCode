#include "BlogInterface.h"

BlogInterface::BlogInterface(const std::string &time_id)
    : time_id_{time_id}
{

}

BlogInterface::~BlogInterface()
{

}

std::string BlogInterface::getId() const
{
    return time_id_;
}
