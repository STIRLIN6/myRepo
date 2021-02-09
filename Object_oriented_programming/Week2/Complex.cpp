#include "Complex.hpp"

Complex::Complex(double re, double im)
{
    this->re = re;
    this->im = im;
}

double Complex::GetRe () const
{
    return re;
}

double Complex::GetIm () const
{
    return im;
}

Complex Complex::operator+(Complex &x)
{
    Complex w = Complex(GetRe() + x.GetRe(), GetIm() + x.GetIm());

    return w;
}

Complex Complex::operator*(Complex &other)
{
    Complex w = Complex(GetRe() * other.GetRe() - GetIm() * other.GetIm(),
                        GetRe() * other.GetIm() + GetIm() * other.GetRe());

    return w;
}

std::ostream &operator<<(std::ostream &os, const Complex &x)
{
    os << x.GetRe() << ((x.GetIm() < 0)?"":"+") << x.GetIm() << "*i";
    return os;
}