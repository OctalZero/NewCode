#include "CommentInterface.h"

CommentInterface::CommentInterface(const std::string &timeId):TimeId_(timeId)
{

}

std::string CommentInterface::getId() const
{
    return TimeId_;
}
