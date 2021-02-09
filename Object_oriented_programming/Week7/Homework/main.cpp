#include <iostream>
#include "HunterEnor.hpp"

int main()
{
    HunterEnor enor("in.txt");
    
    int vadasz = 0;
    
    for (enor.First(); !enor.End(); enor.Next())
    {
        if (enor.Current()) {
            vadasz++;
        }
    }

    std::cout << vadasz << std::endl;
}