#pragma once

#include "Toltohely.hpp"
#include "Penztar.hpp"

class Benzinkut
{
private:
    int egysegar;
    
    const static int tol = 6;
    const static int penz = 2;

    Toltohely toltok[tol];
    Penztar penztar[penz];

public:
    void setEgysegar(int e);
    
    int getEgysegar();

    bool validToltohely (int t);
    bool validPenztar (int p);

    Toltohely& getToltohely(int t);
    Penztar& getPenztar(int p);
};