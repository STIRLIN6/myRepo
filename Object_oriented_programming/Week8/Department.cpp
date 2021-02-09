#include "Department.hpp"
#include <fstream>
#include "Product.hpp"

Department::Department(const std::string &filename)
{
    std::ifstream f(filename);

    std::string name;
    int price;
    while (f >> name >> price)
    {
        products.push_back(new Product(name, price));
    }
}

Department::~Department()
{
    for (Product *p : products)
    {
        delete p;
    }
}

void Department::RemoveStock(Product *p)
{
    bool l = false;
    int ind;

    for (int i = 0; i < products.size() && !l; ++i)
    {
        l = (products[i] == p);
        ind = i;
    }

    if (l)
    {
        products.erase(products.begin() + ind);
    }
    else
    {
        // TERMINATE
    }
}