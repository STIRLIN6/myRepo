#include <iostream>
#include <string>

#include "library/seqinfileenumerator.hpp"
#include "library/stringstreamenumerator.hpp"
#include "library/maxsearch.hpp"
#include "library/summation.hpp"

struct Arany {
    double i;
    double n;
};

struct Szokas {
    std::string name;
    std::string priority;
    Arany arany;
};

struct Success {
    std::string date;
    std::string success;
};

class Counter : public Summation<Success, Arany>
{
    virtual Arany func(const Success& e) const override {
        if ("I" == e.success) {
            return {1, 0};
        }
        else {
            return {0, 1};
        }
    }

    virtual Arany neutral() const override {
        return {0, 0};
    }

    virtual Arany add( const Arany& a, const Arany& b) const override {
        return {a.i + b.i, a.n + b.n};
    }

    virtual bool cond(const Success& e) const override {
        return true;
    }
};

std::istream &operator>> (std::istream &is, Success &x) {
    is >> x.date;
    is >> x.success;

    return is;
}

std::istream &operator>>(std::istream &is, Szokas &x)
{
    std::string line;
    std::getline(is, line);
    std::stringstream ss(line);
    ss >> x.name;
    ss >> x.priority;

    StringStreamEnumerator<Success> lineEnum(ss);
    Counter co;
    co.addEnumerator(&lineEnum);
    co.run();

    x.arany = co.result();

    return is;
}

class MyMax : public MaxSearch < Szokas, double, Less<double> >
{
    virtual double func(const Szokas& e) const override {
        //std::cout << (e.arany.i)/(e.arany.n + e.arany.i) << std::endl;
        return (e.arany.i)/(e.arany.n + e.arany.i);
    }

    virtual bool  cond(const Szokas& e) const { return true;}
};

int main(int argc, char *argv[])
{
    const std::string fileName = argv[1];

    MyMax result;
    SeqInFileEnumerator<Szokas> seqEnor(fileName);

    result.addEnumerator(&seqEnor);
    result.run();
    
    if (result.found()) {
        std::cout << result.optElem().name << std::endl;
    }
    else {
        std::cout << "Empty file." << std::endl;
    }
}
