#include "MaterialInterface.h"

MaterialInterface::MaterialInterface(const std::string &time_id)
    : time_id_{time_id}
{

}

MaterialInterface::~MaterialInterface()
{

}

const std::string MaterialInterface::getId() const
{
    return time_id_;
}
