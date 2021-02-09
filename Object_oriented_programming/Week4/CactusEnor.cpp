#include "CactusEnor.hpp"

std::istream& operator >> (std::istream& is, Cactus& x) {
    is >> x.name;
    is >> x.origin;
    is >> x.color;
    return is;
}

std::ostream& operator << (std::ostream& os, const Cactus& x) {
    os << x.name << " ";
    os << x.origin << " ";
    os << x.color << std::endl;
    return os;
}

CactusEnor::CactusEnor(const std::string& fileName) : f (fileName)
{

}

void CactusEnor::First() {
    Next();
}

void CactusEnor::Next() {
    if (this->f >> this->dx) {
        this->sx = Norm;
    }
    else {
        this->sx = Abnorm;
    }
}

bool CactusEnor::End() const {
    return this->sx == Abnorm;
}

Cactus CactusEnor::Current() const {
    return dx;
}