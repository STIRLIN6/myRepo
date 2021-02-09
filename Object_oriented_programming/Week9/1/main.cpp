#include <iostream>
#include "Entry.hpp"
#include "File.hpp"
#include "Directory.hpp"

int main()
{
    Directory root("root");

    root.AddEntry(std::make_unique<Directory>("home"));
    root.AddEntry(std::make_unique<File>("teszt 1", 5));
    root.AddEntry(std::make_unique<File>("teszt 2", 10));

    std::cout << root.GetSize() << std::endl;
}