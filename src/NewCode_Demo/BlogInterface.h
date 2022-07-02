#ifndef BLOGINTERFACE_H
#define BLOGINTERFACE_H
#include <nlohmann/json.hpp>

class BlogInterface
{
public:
    explicit BlogInterface(const std::string &timeId);
    virtual ~BlogInterface(){}

    virtual nlohmann::json getAbstract()= 0;
    virtual nlohmann::json getDetail()= 0;

    std::string getId() const;

private:
    std::string TimeId_;
};

#endif // BLOGINTERFACE_H
