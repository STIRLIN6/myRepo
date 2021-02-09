#include "OrderEnor.hpp"
#include <iostream>

int main()
{
    OrderEnor e("in.txt");
    bool l = true;

    for (e.First(); !e.End(); e.Next())
    {
        if (l && e.Current().atLeast20k) {
            l = false;
        }
    }

    if (!l) {
        std::cout << "Van olyan szamla, ami csak legalabb 20 000 Ft-os termeket tartalmaz." << std::endl;
    }
    else {
        std::cout << "Nincs olyan szamla, ami csak  legalabb 20 000 Ft-os termeket tartalmaz." << std::endl;
    }
}