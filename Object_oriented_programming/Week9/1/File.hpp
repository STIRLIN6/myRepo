#pragma once

#include "Entry.hpp"

class File : public Entry
{
private:
    int size;

public:
    File(const std::string &name, int size);

    virtual int GetSize() const override;
};