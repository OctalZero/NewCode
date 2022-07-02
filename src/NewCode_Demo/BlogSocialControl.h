#ifndef BLOGSOCIALCONTROL_H
#define BLOGSOCIALCONTROL_H
#include <nlohmann/json.hpp>

class BlogSocialControl
{
    explicit BlogSocialControl();
    ~BlogSocialControl();
    nlohmann::json login(std::string netizenId);
};

#endif // BLOGSOCIALCONTROL_H
