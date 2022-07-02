#ifndef COMMENTINTERFACE_H
#define COMMENTINTERFACE_H
#include <nlohmann/json.hpp>

class CommentInterface
{
public:
    explicit CommentInterface(const std::string &timeId);
    virtual ~CommentInterface(){}

    virtual nlohmann::json getInfo()=0;

    std::string getId() const;
private:
    std::string TimeId_;
};

#endif // COMMENTINTERFACE_H
