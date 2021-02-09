#pragma once

#include "EntryVisitor.hpp"

class CountLargeFilesVisitor : public EntryVisitor
{
private:
    int c = 0;
    int lowerBound;

public:
    CountLargeFilesVisitor(int lowerBound);

    virtual void VisitDirectory(const Directory &dir) override;
    virtual void VisitFile(const File &file) override;

    int GetNumberOfLargeFiles() const { return c; }
};