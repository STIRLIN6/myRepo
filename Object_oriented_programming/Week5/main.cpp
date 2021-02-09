#include "OrderEnor.hpp"
#include <iostream>

int main()
{
    OrderEnor e("in.txt");
    int total = 0;
    bool nincs = true;

    for (e.First(); !e.End(); e.Next())
    {
        // std::cout << e.Current().name << " " << e.Current().sum << std::endl;
        total += e.Current().sum;
        
        if (nincs && e.Current().atLeast20k) {
            nincs = false;
        }
    }

    std::cout << total << std::endl;
    if (!nincs) {
        std::cout << "Van olyan szamla, ami csak legalabb 20 000 Ft-os termeket tartalmaz." << std::endl;
    }
    else {
        std::cout << "Nincs olyan szamla, ami csak  legalabb 20 000 Ft-os termeket tartalmaz." << std::endl;
    }
}