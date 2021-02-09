#pragma once
#include <string>
#include <fstream>

struct Cactus {
    std::string name;
    std::string origin;
    std::string color;
};

std::istream& operator >> (std::istream& is, Cactus& x);
std::ostream& operator << (std::ostream& os, const Cactus& x);

class CactusEnor
{
public:
    CactusEnor(const std::string& fileName);

    void First();
    void Next();

    bool End() const;
    Cactus Current() const;

private:
    enum Status {
        Norm,
        Abnorm
    };

    std::ifstream f;
    Cactus dx;
    Status sx;
};