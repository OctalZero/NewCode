#include "MaterialInterface.h"

MaterialInterface::MaterialInterface(const std::string &time_id):TimeId_(time_id)
{

}

const std::string MaterialInterface::getId() const
{
    return TimeId_;
}
