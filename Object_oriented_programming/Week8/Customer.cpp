#include "Customer.hpp"

#include <fstream>
#include "Product.hpp"
#include "Store.hpp"

static Product *LinSearch(const std::vector<Product *> &products, const std::string &productName)
{
    for (Product *p : products)
    {
        if (p->GetName() == productName)
        {
            return p;
        }
    }
    return nullptr;
}

static Product *MinSearch(const std::vector<Product *> &products, const std::string &productName)
{
    bool l = false;
    Product *elem;
    int min;

    for (Product *p : products)
    {
        if (!l && p->GetName() == productName)
        {
            elem = p;
            min = p->GetPrice();
            l = true;
        }
        else if (l && p->GetName() == productName && p->GetPrice() < min)
        {
            elem = p;
            min = p->GetPrice();
        }
    }

    if (l)
        return elem;
    else
        return nullptr;
}

Customer::Customer(const std::string &listPath)
{
    std::ifstream f(listPath);
    std::string name;
    while (f >> name)
    {
        list.push_back(name);
    }
}

void Customer::Purchase(Store &store)
{
    for (const std::string &pn : list)
    {
        Product *p = LinSearch(store.food.products, pn);
        if (p != nullptr)
        {
            cart.push_back(p);
            store.food.RemoveStock(p);
        }
        else
        {
        }
    }

    for (const std::string &pn : list)
    {
        Product *p = MinSearch(store.tech.products, pn);
        if (p != nullptr)
        {
            cart.push_back(p);
            store.tech.RemoveStock(p);
        }
        else
        {
        }
    }
}

void Customer::PrintCart(std::ostream &os) const
{
    for (Product *p : cart)
    {
        os << p->GetName() << ": " << p->GetPrice() << std::endl;
    }
}

Customer::~Customer()
{
    for (Product *p : cart)
    {
        delete p;
    }
}