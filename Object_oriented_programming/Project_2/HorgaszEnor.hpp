#pragma once
#include <string>
#include <fstream>
#include <vector>

struct Adat {
    std::string horgasz;
    std::string verseny;
    bool csakharcsa;
    bool legalabb3;
};

std::istream& operator >> (std::istream& is, Adat& x);

class HorgaszEnor
{
public:
    HorgaszEnor(const std::string& fileName);

    void First();
    void Next();
    bool End() const;
    Adat Current() const;

private:
    enum Status {
        Norm,
        Abnorm
    };

    std::ifstream f;
    Adat dx;
    Status sx;
};