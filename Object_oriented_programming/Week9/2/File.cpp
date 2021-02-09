#include "File.hpp"
#include "EntryVisitor.hpp"

File::File(const std::string &name, int size) : Entry(name), size(size) {}

int File::GetSize() const
{
    return size;
}

void File::Accept(EntryVisitor &visitor) const
{
    visitor.VisitFile(*this);
}