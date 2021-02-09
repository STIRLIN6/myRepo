#include <iostream>

#include "Customer.hpp"
#include "Store.hpp"

int main()
{
    Customer c("customer1.txt");
    Store s("foods.txt", "tech.txt");

    c.Purchase(s);
    c.PrintCart(std::cout);
}