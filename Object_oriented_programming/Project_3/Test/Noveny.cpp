#include "Noveny.hpp"

Puffancs::Puffancs(const std::string &name, int quantity) : Noveny(name, quantity) {}

void Puffancs::alfa(Bolygo &b) { _quantity += 2; b.alfaigeny += 10; }
void Puffancs::delta(Bolygo &b) { _quantity -= 2; b.alfaigeny += 10; }
void Puffancs::nincs(Bolygo &b) { _quantity -= 1; b.alfaigeny += 10; }

bool Puffancs::alive() { return  (_alive = _quantity > 0 && _quantity < 10); }

///

Deltafa::Deltafa(const std::string &name, int quantity) : Noveny(name, quantity) {}

void Deltafa::alfa(Bolygo &b) {
    _quantity -= 3;

    if (_quantity < 5) {
        b.deltaigeny += 4;
    }
    else if (_quantity >= 5 && _quantity <= 10) {
        b.deltaigeny++;
    }
}

void Deltafa::delta(Bolygo &b) {
    _quantity += 4;
    
    if (_quantity < 5) {
        b.deltaigeny += 4;
    }
    else if (_quantity >= 5 && _quantity <= 10) {
        b.deltaigeny++;
    }
}

void Deltafa::nincs(Bolygo &b) {
    _quantity -= 1;
    
    if (_quantity < 5) {
        b.deltaigeny += 4;
    }
    else if (_quantity >= 5 && _quantity <= 10) {
        b.deltaigeny++;
    }
}

///

Parabokor::Parabokor(const std::string &name, int quantity) : Noveny(name, quantity) {}

void Parabokor::alfa(Bolygo &b) { _quantity += 1; }
void Parabokor::delta(Bolygo &b) { _quantity += 1; }
void Parabokor::nincs(Bolygo &b) { _quantity -= 1; }