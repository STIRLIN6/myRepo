#include "HorgaszEnor.hpp"
#include <sstream>
#include <iostream>

std::istream& operator >> (std::istream& is, Adat& x)
{
    is >> x.horgasz;
    is >> x.verseny;

    std::string line;
    std::getline(is, line);
    std::stringstream ss (line);

    x.csakharcsa = true;
    x.legalabb3 = false;

    std::string halTemp;
    int meretTemp;
    int db = 0;
    while (ss >> halTemp) {
        ss >> meretTemp;
        
        if ("Harcsa" != halTemp) {
            x.csakharcsa = false;
        }

        db++;
    }
    if (db > 2) {
        x.legalabb3 = true;
    }

    return is;
}

HorgaszEnor::HorgaszEnor(const std::string& fileName) : f (fileName) {}

void HorgaszEnor::First() {
    Next();
}

void HorgaszEnor::Next() {
    if (this->f >> this->dx) {
        this->sx = Norm;
    }
    else {
        this->sx = Abnorm;
    }
}

bool HorgaszEnor::End() const {
    return this->sx == Abnorm;
}

Adat HorgaszEnor::Current() const {
    return dx;
}