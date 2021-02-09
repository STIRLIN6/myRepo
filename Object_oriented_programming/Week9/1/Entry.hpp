#pragma once

#include <string>

class Entry
{
private:
    std::string name;

protected:
    Entry(const std::string &name);

public:
    virtual ~Entry() = default;
    virtual int GetSize() const = 0;
    const std::string &GetName() const;
};