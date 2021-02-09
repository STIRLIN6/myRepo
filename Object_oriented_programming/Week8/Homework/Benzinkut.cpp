#include "Benzinkut.hpp"

void Benzinkut::setEgysegar(int e) {
    this->egysegar = e;
}

int Benzinkut::getEgysegar() {
    return egysegar;
}

bool Benzinkut::validToltohely (int t) {
    return t >= 0 && t <= tol;
}
    
bool Benzinkut::validPenztar (int p) {
    return p >= 0 && p <= penz;
}

Toltohely& Benzinkut::getToltohely(int t) {
    return toltok[t];
}

Penztar& Benzinkut::getPenztar(int p) {
    return penztar[p];
}