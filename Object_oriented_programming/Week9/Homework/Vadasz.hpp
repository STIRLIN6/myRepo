#pragma once

#include <string>
#include "Vad.hpp"
#include <vector>

class Vadasz
{
private:
    std::string _nev;
    int _eletkor;
    std::vector<Vad*> trofeak;

public:
    Vadasz(std::string nev, int eletkor) : _nev(nev), _eletkor(eletkor) {}

    ~Vadasz();
    
    int himOroszlanok;

    void adder (Vad* trofea);

    void counter();
};