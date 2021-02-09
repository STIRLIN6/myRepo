#include "OrderEnor.hpp"
#include <sstream>

OrderEnor::OrderEnor(const std::string &fileName) : x(fileName)
{
}

void OrderEnor::First()
{
    Next();
}

void OrderEnor::Next()
{
    Read();
}

bool OrderEnor::End() const
{
    return sx == Abnorm;
}

Order OrderEnor::Current() const
{
    return dx;
}

void OrderEnor::Read()
{
    std::string line;
    if (std::getline(x, line))
    {
        sx = Norm;
        std::stringstream s(line);

        s >> dx.name;
        dx.sum = 0;
        dx.atLeast20k = true;
        
        std::string productName;
        int productPrice;
        while (s >> productName >> productPrice)
        {
            dx.sum += productPrice;
            if (productPrice < 20000) { dx.atLeast20k = false; };
        }
    }
    else
    {
        sx = Abnorm;
    }
}