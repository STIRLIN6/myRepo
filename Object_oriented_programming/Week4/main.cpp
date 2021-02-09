#include "CactusEnor.hpp"
#include <iostream>

int main ()
{
    CactusEnor enor("in.txt");
    std::ofstream p ("piros.txt");
    for(enor.First(); !enor.End(); enor.Next()) {
        //std::cout << enor.Current() << std::endl;
        Cactus curr = enor.Current();
        if (curr.color == "piros") {
            p << enor.Current();
        }
    }
}