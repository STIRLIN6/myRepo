#include "Penztar.hpp"

#include "Benzinkut.hpp"

int Penztar::fizet(Benzinkut *bk, Toltohely& th) {
    int temp = th.getKijelzo();
    th.lenullaz();
    return temp * bk->getEgysegar();
}