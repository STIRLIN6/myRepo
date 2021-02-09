#pragma once

#include <string>
#include <fstream>

struct Hunting
{
    std::string hunterName;
    bool rabbit;
    bool deer250;
};

struct Hunter {
    std::string hunterName;
    bool allRabbit;
    bool exist;
};

class HunterEnor
{
public:
    HunterEnor(const std::string &fileName);

    void First();
    void Next();

    bool End() const;
    bool Current() const;

private:
    void Read();

    enum Status
    {
        Abnorm,
        Norm
    };

    std::ifstream f;
    Status sf;
    Hunting df;

    bool end;
    Hunter current;
    std::string hunterName;
};