#pragma once

#include <string>
#include <vector>

class Store;
class Product;

class Customer
{
public:
    Customer(const std::string &listPath);
    ~Customer();
    void Purchase(Store &store);

    void PrintCart(std::ostream &os) const;

private:
    std::vector<std::string> list;
    std::vector<Product *> cart;
};