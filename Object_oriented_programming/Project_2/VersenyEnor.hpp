#pragma once

#include "HorgaszEnor.hpp"

struct Verseny
{
    std::string verseny;
    int occurrence;
};

class VersenyEnor
{
public:
    VersenyEnor (const std::string &str): _tt(str) { };

    void first() { _tt.First(); next(); }
    void next();

    Verseny current() const { return _cur; }
    bool end() const { return _end; }

private:
    HorgaszEnor _tt;
    Verseny _cur;
    bool _end;
};