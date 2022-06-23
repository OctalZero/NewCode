#include "NetizenInterface.h"

NetizenInterface::NetizenInterface(const std::string& id)
	: id_(id)
{
}

NetizenInterface::~NetizenInterface()
{
}

std::string NetizenInterface::getId() const
{
	return id_;
}
