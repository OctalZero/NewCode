#include "MaterialInterface.h"

MaterialInterface::MaterialInterface(const std::string& id)
	: time_id_{ id }
{
}

MaterialInterface::~MaterialInterface()
{
}

std::string MaterialInterface::getId() const
{
	return time_id_;
}
