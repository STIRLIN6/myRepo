#pragma once

#include <string>

class Product
{
public:
    Product(std::string name, int price) : name(name), price(price) {}

    const std::string &GetName() const;
    int GetPrice() const;

private:
    std::string name;
    int price;
};