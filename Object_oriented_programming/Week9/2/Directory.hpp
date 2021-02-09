#pragma once

#include "Entry.hpp"
#include <vector>
#include <memory>

#include <iostream>

class Directory : public Entry
{
private:
    std::vector<std::unique_ptr<Entry>> entries;

public:
    Directory(const std::string &name);
    Directory(const std::string &name, std::istream &is);

    virtual int GetSize() const override;
    virtual void Accept(EntryVisitor &visitor) const override;

    void AddEntry(std::unique_ptr<Entry> entry);
};