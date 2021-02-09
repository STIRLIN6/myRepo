#pragma once

#include <vector>
#include <string>

class Product;

class Department
{
public:
    Department(const std::string &filename);
    ~Department();

    void RemoveStock(Product *p);
    // private:
    std::vector<Product *> products;
};