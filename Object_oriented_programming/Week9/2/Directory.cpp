#include "Directory.hpp"
#include "EntryVisitor.hpp"

Directory::Directory(const std::string &name) : Entry(name)
{
}

Directory::Directory(const std::string &name, std::istream &is) : Entry(name)
{
    std::string line;
    while (std::getline(is, line) && line != "")
    {
        AddEntry(CreateEntry(is, line));
    }
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

void Directory::Accept(EntryVisitor &visitor) const
{
    visitor.VisitDirectory(*this);
    for (unsigned i = 0; i < entries.size(); ++i)
    {
        entries[i]->Accept(visitor);
    }
}

void Directory::AddEntry(std::unique_ptr<Entry> entry)
{
    entries.push_back(std::move(entry));
}
