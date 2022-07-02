#ifndef MATERIALINTERFACE_H
#define MATERIALINTERFACE_H

#include <string>

class MaterialInterface
{
public:
    explicit MaterialInterface(const std::string &time_id);
    virtual  ~MaterialInterface(){}

    virtual std::string getAbstract()  = 0;
    const std::string getId() const;

private:
    std::string TimeId_;
};

#endif // MATERIALINTERFACE_H
