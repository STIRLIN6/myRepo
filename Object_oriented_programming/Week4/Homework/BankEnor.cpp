#include "BankEnor.hpp"

std::istream& operator >> (std::istream& is, Account& x) {
    is >> x.name;
    is >> x.balance;
    return is;
}

BankEnor::BankEnor (const std::string& fileName) : f (fileName) {

}

void BankEnor::First() {
    Next();
}

void BankEnor::Next() {
    if (this->f >> this->dx) {
        this->sx = Norm;
    }
    else {
        this->sx = Abnorm;
    }
}

bool BankEnor::End() const {
    return this->sx == Abnorm;
}

Account BankEnor::Current() const {
    return dx;
}