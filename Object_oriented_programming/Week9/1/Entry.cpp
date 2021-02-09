#include "Entry.hpp"

Entry::Entry(const std::string &name) : name(name)
{
}

const std::string &Entry::GetName() const
{
    return name;
}
