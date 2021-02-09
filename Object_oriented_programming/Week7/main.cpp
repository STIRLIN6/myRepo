#include <iostream>
#include "HunterEnor.hpp"

int main()
{
    HunterEnor enor("in.txt");
    bool everyHunter = true;
    for (enor.First(); everyHunter && !enor.End(); enor.Next())
    {
        everyHunter = enor.Current();
    }

    if (everyHunter)
    {
        std::cout << "Minden vadasz lott legalabb egy vadaszaton medvet" << std::endl;
    }
    else
    {
        std::cout << "Volt olyan vadasz aki egyszer sem lott medvet" << std::endl;
    }
}