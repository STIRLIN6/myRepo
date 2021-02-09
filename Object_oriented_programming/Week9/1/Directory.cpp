#include "Directory.hpp"

Directory::Directory(const std::string &name) : Entry(name)
{
}

int Directory::GetSize() const
{
    int size = 0;
    for (unsigned i = 0; i < entries.size(); ++i)
    {
        size += entries[i]->GetSize();
    }
    return size;
}

void Directory::AddEntry(std::unique_ptr<Entry> entry)
{
    entries.push_back(std::move(entry));
}
