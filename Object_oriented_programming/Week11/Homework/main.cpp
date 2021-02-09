#include <iostream>
#include <string>
#include <sstream>

#include "library/summation.hpp"
#include "library/maxsearch.hpp"
#include "library/enumerator.hpp"
#include "library/seqinfileenumerator.hpp"
#include "library/stringstreamenumerator.hpp"

struct Person
{
    std::string name;
    int maxSum;
};

struct Shopping
{
    std::string name;
    int sum;
};

class Vegosszeg : public Summation<int, int>
{
    virtual int func(const int& e) const override {
        return e;
    }

    virtual int neutral() const override {
        return 0;
    }

    virtual int add( const int& a, const int& b) const override {
        return a + b;
    }

    virtual bool cond(const int& e) const override { return true; }
};

std::istream &operator>>(std::istream &is, Shopping &x)
{

    std::string line;
    std::getline(is, line);
    std::stringstream s(line);
    s >> x.name;

    StringStreamEnumerator<int> tetel(s);
    Vegosszeg veg;
    veg.addEnumerator(&tetel);
    veg.run();
    x.sum = veg.result();

    return is;
}

class MaxVegosszeg : public MaxSearch<Shopping, int>
{
    virtual void first() override {  }

    virtual int func(const Shopping &e) const override
    {
        return e.sum;
    }

    virtual bool whileCond(const Shopping &current) const override
    {
        return current.name == name;
    }

public:
    MaxVegosszeg(const std::string &name) : name(name) {}
private:
    std::string name;
};

class Nevek : public Enumerator<Person>
{
public:
    Nevek(const std::string& fname) : f(fname) {}

    void first() override {
        f.first();
        next();
    }

    void next() override {
        _end = f.end();
        if(_end) {
            return;
        }

        curr.name = f.current().name;

        MaxVegosszeg m(curr.name);
        m.addEnumerator(&f);
        m.run();

        curr.maxSum = m.optElem().sum;
    }

    bool end() const override { return _end; }
    Person current() const override { return curr; }

    SeqInFileEnumerator<Shopping> f;
    Person curr;
    bool _end;
};

class Summ : public Summation<Person, std::ostream>
{
    //virtual void first() override {  } ////////////////

    virtual std::string func(const Person& e) const override {
        return e.name + '\n';
    }

    virtual bool cond(const Person& e) const override { return e.maxSum > 5000; }

public:
    Summ(std::ostream* o) : Summation<Person, std::ostream>(o) {}

    
};

int main()
{
    Summ s(&(std::cout));

    Nevek enum1("in3.txt");
    s.addEnumerator(&enum1);
    s.run();
}