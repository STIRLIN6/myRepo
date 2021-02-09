#include "File.hpp"

File::File(const std::string &name, int size) : Entry(name), size(size) {}

int File::GetSize() const
{
    return size;
}
