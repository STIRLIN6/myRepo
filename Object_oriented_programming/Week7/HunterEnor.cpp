#include "HunterEnor.hpp"
#include <sstream>

HunterEnor::HunterEnor(const std::string &fileName) : f(fileName)
{
}

void HunterEnor::Read()
{
    std::string line;
    if (std::getline(f, line))
    {
        sf = Norm;

        std::stringstream s(line);
        s >> df.hunterName;
        df.shotBear = false;

        std::string preyName;
        int preyWeight;
        while (!df.shotBear && s >> preyName >> preyWeight)
        {
            if (preyName == "medve")
            {
                df.shotBear = true;
            }
        }
    }
    else
    {
        sf = Abnorm;
    }
}

void HunterEnor::First()
{
    Read();
    Next();
}

void HunterEnor::Next()
{
    end = (sf == Abnorm);
    if (end)
        return;

    current = false;
    hunterName = df.hunterName;

    while (sf == Norm && df.hunterName == hunterName)
    {
        current = current || df.shotBear;
        Read();
    }
}

bool HunterEnor::End() const
{
    return end;
}

bool HunterEnor::Current() const
{
    return current;
}