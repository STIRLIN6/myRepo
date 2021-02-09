#pragma once
#include <string>
#include <fstream>

struct Order
{
    std::string name;
    bool atLeast20k;
};

class OrderEnor
{
public:
    OrderEnor(const std::string &fileName);

    void First();
    void Next();

    bool End() const;
    Order Current() const;

private:
    void Read();

    enum Status
    {
        Norm,
        Abnorm
    };

    std::ifstream x;
    Order dx;
    Status sx;
};