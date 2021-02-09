#pragma once

class Directory;
class File;

class EntryVisitor
{
public:
    virtual void VisitDirectory(const Directory &dir) = 0;
    virtual void VisitFile(const File &file) = 0;
};