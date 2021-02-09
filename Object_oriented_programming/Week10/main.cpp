#include <iostream>
#include <string>
#include <sstream>
#include "library/maxsearch.hpp"
#include "library/summation.hpp"
#include "library/stringstreamenumerator.hpp"
#include "library/seqinfileenumerator.hpp"

struct Student
{
    std::string name;
    double average;
};

struct StudentAverage
{
    int sum;
    int count;
};

class Average : public Summation<int, StudentAverage>
{
    virtual StudentAverage func(const int &e) const override
    {
        return {e, 1};
    }

    virtual StudentAverage neutral() const override
    {
        return {0, 0};
    }

    virtual StudentAverage add(const StudentAverage &a, const StudentAverage &b) const override
    {
        return {
            a.sum + b.sum,
            a.count + b.count};
    }
};

std::istream &operator>>(std::istream &is, Student &x)
{
    std::string line;
    std::getline(is, line);
    std::stringstream s(line);
    s >> x.name;

    StringStreamEnumerator<int> grades(s);
    Average avg;
    avg.addEnumerator(&grades);
    avg.run();
    x.average = static_cast<double>(avg.result().sum) / avg.result().count;

    return is;
}

class BestStudent : public MaxSearch<Student, double>
{
    virtual double func(const Student &e) const override
    {
        return e.average;
    }
};

int main()
{
    BestStudent x;
    SeqInFileEnumerator<Student> studentEnor("in.txt");
    x.addEnumerator(&studentEnor);
    x.run();

    std::cout << x.optElem().name << ": " << x.opt() << std::endl;
}
