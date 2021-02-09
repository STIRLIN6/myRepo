#pragma once

#include <string>
#include <memory>

class EntryVisitor;

class Entry
{
private:
    std::string name;

protected:
    Entry(const std::string &name);

public:
    virtual ~Entry() = default;
    virtual int GetSize() const = 0;
    virtual void Accept(EntryVisitor &visitor) const = 0;
    const std::string &GetName() const;
};

std::unique_ptr<Entry> CreateEntry(std::istream &is, const std::string &line);
