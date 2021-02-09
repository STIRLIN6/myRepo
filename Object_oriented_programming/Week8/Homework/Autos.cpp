#include "Autos.hpp"

void Autos::setFizetett(int f) {
    fizetett = f;
}

void Autos::tankol(Benzinkut& benzinkut, int toltohely, int penztar, int mennyiseg) {
    if (benzinkut.validToltohely(toltohely)) {
        benzinkut.getToltohely(toltohely).tolt(mennyiseg);
    }
    else {
        return;
    }

    if (benzinkut.validPenztar(penztar)) {
        this->setFizetett(benzinkut.getPenztar(penztar).fizet(&benzinkut, benzinkut.getToltohely(toltohely)));
    }
}

int Autos::getFizetett() {
    return fizetett;
}