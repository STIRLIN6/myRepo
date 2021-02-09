#pragma once

#include <iostream>

class Complex
{
public:
    Complex(double re, double im);
    
    double GetRe() const;
    double GetIm() const;
    
    Complex operator + (Complex& x);
    Complex operator * (Complex& other);

private: 
    double re;
    double im;
};

std::ostream& operator << (std::ostream& os, const Complex& x);