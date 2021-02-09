#pragma once

#include "Entry.hpp"

class File : public Entry
{
private:
    int size;

public:
    File(const std::string &name, int size);
    virtual void Accept(EntryVisitor &visitor) const override;

    virtual int GetSize() const override;
};