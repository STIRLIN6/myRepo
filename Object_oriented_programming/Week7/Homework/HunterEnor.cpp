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
        df.rabbit = false;
        df.deer250 = false;

        std::string preyName;
        int preyWeight;

        while (s >> preyName >> preyWeight)
        {
            if (preyName == "nyul")
            {
                df.rabbit = true;
            }
            if (preyName == "szarvas" && preyWeight > 250)
            {
                df.deer250 = true;
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
    if (end) { return; }

    current.allRabbit = true;
    current.exist = false;
    hunterName = df.hunterName;

    while (sf == Norm && df.hunterName == hunterName)
    {
        current.allRabbit = current.allRabbit && df.rabbit;
        current.exist = current.exist || df.deer250;
        Read();
    }

}

bool HunterEnor::End() const
{
    return end;
}

bool HunterEnor::Current() const
{
    return current.exist && current.allRabbit;
}