#pragma once

#include "Entry.hpp"
#include <vector>
#include <memory>

class Directory : public Entry
{
private:
    std::vector<std::unique_ptr<Entry>> entries;

public:
    Directory(const std::string &name);

    virtual int GetSize() const override;
    void AddEntry(std::unique_ptr<Entry> entry);
};