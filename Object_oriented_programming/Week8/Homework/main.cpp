#include "Benzinkut.hpp"
#include "Autos.hpp"

#include <iostream>

int main() {
    Autos a;
    Benzinkut b;

    int egysegar = 300; b.setEgysegar(egysegar);
    int toltohely = 3;
    int penztar = 1;
    int mennyiseg = 6;

    a.tankol(b, toltohely, penztar, mennyiseg);

    std::cout << a.getFizetett() << std::endl;
}