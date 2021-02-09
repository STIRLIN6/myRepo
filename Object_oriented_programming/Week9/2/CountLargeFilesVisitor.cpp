#include "CountLargeFilesVisitor.hpp"

#include "File.hpp"
#include "Directory.hpp"

CountLargeFilesVisitor::CountLargeFilesVisitor(int lowerBound) : lowerBound(lowerBound)
{
}

void CountLargeFilesVisitor::VisitDirectory(const Directory &dir)
{
}

void CountLargeFilesVisitor::VisitFile(const File &file)
{
    if (file.GetSize() > lowerBound)
    {
        ++c;
    }
}