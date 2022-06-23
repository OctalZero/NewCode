#include "CommentInterface.h"

CommentInterface::CommentInterface(const std::string& id)
	: time_id_{ id }
{
}

CommentInterface::~CommentInterface()
{
}

std::string CommentInterface::getId() const
{
	return time_id_;
}
