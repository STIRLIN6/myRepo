#include <iostream>
#include "Entry.hpp"
#include <fstream>
#include "CountLargeFilesVisitor.hpp"

std::unique_ptr<Entry> CreateFileSystem()
{
    std::ifstream f("in.txt");
    std::string line;
    std::getline(f, line);
    return CreateEntry(f, line);
}

int main()
{
    std::unique_ptr<Entry> rootDir = CreateFileSystem();
    // std::cout << rootDir->GetSize() << std::endl;

    CountLargeFilesVisitor visitor(50);
    rootDir->Accept(visitor);
    std::cout << visitor.GetNumberOfLargeFiles() << std::endl;
}