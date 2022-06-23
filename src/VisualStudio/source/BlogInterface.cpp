#include "BlogInterface.h"

BlogInterface::BlogInterface(const std::string& id)
	: time_id_{ id }
{
}

BlogInterface::~BlogInterface()
{
}

std::string BlogInterface::getId() const
{
	return time_id_;
}
