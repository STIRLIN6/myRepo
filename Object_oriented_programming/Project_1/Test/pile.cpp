#include "pile.hpp"
#include <iostream>

Pile::Pile() {
    sumCounter = 0;
}

void Pile::add (int n) {
    int i;
    for (i = 0; i < this->numbers.size() && n != this->numbers[i]; i++);
    
    if (i == this->numbers.size()) {
        this->numbers.push_back(n);
        sumCounter += n;
    }
    else {
        throw ITEM_IS_ALREDY_CONTAINED;
    }
}

void Pile::remove (int n) {
    int i = 0;
    for (; i < this->numbers.size() && n != this->numbers[i]; i++);

    if (i == this->numbers.size()) {
        throw ITEM_IS_NOT_CONTAINED;
    }
    else {
        numbers.erase(numbers.begin() + i);
        this->sumCounter -= n;
    }
}

int Pile::sum() {
    return sumCounter;
}

int Pile::select (int n) {
    int i = 0;
    for (; i < this->numbers.size() && n != this->numbers[i]; i++);
    if (i == this->numbers.size()) {
        throw ITEM_IS_NOT_CONTAINED;
    }
    return this->numbers[i];
}

void Pile::print() {
    for (int i = 0; i < this->numbers.size(); i++) {
        std::cout << this->numbers[i] << " ";
    }
    std::cout << std::endl;
}

int Pile::size() {
    return this->numbers.size();
}