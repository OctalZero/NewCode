#include "NetizenInterface.h"


NetizenInterface::NetizenInterface(const std::string &tid):Id_(tid)
{

}

std::string NetizenInterface::getId()const
{
    return Id_;
}
