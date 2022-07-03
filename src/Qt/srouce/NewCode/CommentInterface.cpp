#include "CommentInterface.h"

CommentInterface::CommentInterface(const std::string &time_id)
    :time_id_(time_id)
{

}

CommentInterface::~CommentInterface()
{

}

std::string CommentInterface::getId() const
{
    return time_id_;
}
