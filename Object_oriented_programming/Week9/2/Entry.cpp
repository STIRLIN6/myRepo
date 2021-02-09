#include "Entry.hpp"
#include "File.hpp"
#include "Directory.hpp"
#include <sstream>

Entry::Entry(const std::string &name) : name(name)
{
}

const std::string &Entry::GetName() const
{
    return name;
}

std::unique_ptr<Entry> CreateEntry(std::istream &is, const std::string &line)
{
    std::stringstream s(line);
    std::string entryType;
    std::string name;
    s >> entryType >> name;
    if (entryType == "DIR")
    {
        return std::make_unique<Directory>(name, is);
    }
    else if (entryType == "FILE")
    {
        int size;
        s >> size;
        return std::make_unique<File>(name, size);
    }

    throw std::runtime_error("Invalid input file: " + entryType);
}