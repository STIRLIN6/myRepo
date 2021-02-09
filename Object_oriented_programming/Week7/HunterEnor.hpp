#pragma once

#include <string>
#include <fstream>

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

    struct Hunting
    {
        std::string hunterName;
        bool shotBear;
    };

    std::ifstream f;
    Status sf;
    Hunting df;

    bool end;
    bool current;
    std::string hunterName;
};