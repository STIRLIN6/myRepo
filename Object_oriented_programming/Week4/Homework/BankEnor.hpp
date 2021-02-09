#pragma once
#include <string>
#include <fstream>

struct Account
{
    std::string name;
    int balance;
};

std::istream& operator >> (std::istream& is, Account& x);

class BankEnor
{
public:
    BankEnor(const std::string& filename);

    void First();
    void Next();

    bool End() const;
    Account Current() const;

private:
    enum Status {
        Norm,
        Abnorm
    };

    std::ifstream f;
    Account dx;
    Status sx;

};