#include "OccurrenceEnumerator.hpp"
#include <iostream>

int main()
{
    OccurrenceEnumerator enor("in.txt");
    for (enor.First(); !enor.End(); enor.Next())
    {
        std::cout << enor.Current().value << " " << enor.Current().occurrence << std::endl;
    }
}