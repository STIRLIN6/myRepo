#pragma once

#include "Benzinkut.hpp"

class Autos
{
private:
    int fizetett;
public:
    void setFizetett(int f);
    int getFizetett();
    void tankol(Benzinkut& benzinkut, int toltohely, int penztar, int mennyiseg);
};