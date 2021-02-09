#include "Vadasz.hpp"
#include <iostream>

void Vadasz::adder (Vad* trofea) {
    this->trofeak.push_back(trofea);
}

void Vadasz::counter () {
    this->himOroszlanok = 0;
    for (size_t i = 0; i < trofeak.size(); i++) {
        //std::cout << "1" << std::endl;
        if (trofeak[i]->getFajta() == "oroszlan") {
            //std::cout << "2" << std::endl;

            //std::cout << trofeak[i]->getNem() << std::endl;

            if (trofeak[i]->getNem() == "him") {
                //std::cout << "2" << std::endl;
                this->himOroszlanok++;
            }
        }
    }
}

Vadasz::~Vadasz() {
    for (size_t i = 0; i < trofeak.size(); i++) {
        delete trofeak[i];
    }
}