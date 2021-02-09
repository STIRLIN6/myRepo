#include "Complex.hpp"
#include <iostream>

using namespace std;

int main ()
{
    Complex x = Complex(3, -2);
    Complex y = Complex(4, 1);

    cout << x << endl;
    cout << y << endl;

    cout << (x + y) << endl;
    cout << (x * y) << endl;

    return 0;
}