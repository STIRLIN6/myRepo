#include <iostream>
#include "library/maxsearch.hpp"
#include "library/seqinfileenumerator.hpp"

#include "library/intervalenumerator.hpp"
#include "library/linsearch.hpp"

class divSearch : public LinSearch< int, false > {
    int def;
    
    bool cond(const int& e) const override {
        return 0 == def % e;
    }

public:
    divSearch(int def) {
        this->def = def;
    }
};

class SmallestPrime : public MaxSearch< int, int, Less<int> >
{
    int func(const int& e) const override {
        return e;
    }

    bool cond(const int& e) const override {
        IntervalEnumerator a(2, e-1);
        divSearch x = divSearch(e);
        x.addEnumerator(&a);
        x.run();

        if (e == 1) {
            return false;
        }
        
        return !x.found();
    }
};

int main()
{
    SmallestPrime x;
    SeqInFileEnumerator<int> numberEnor("input.txt");
    x.addEnumerator(&numberEnor);
    x.run();

    std::cout << x.optElem() << std::endl;
}