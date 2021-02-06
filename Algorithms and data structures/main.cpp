#include "Lista.hpp"
#include "Polynomial.hpp"
#include <vector>
#include <iostream>

int main()
{
    std::cout << "na halo" << std::endl;

    std::vector<int> a;
    for (int i = 0; i <= 3; i++) {
        a.push_back(3);
        a.push_back(3-i);
    }
    
    Polynomial A(a);
    ElemLista* p1 = A.polinom->next;
    for (int i = 0; i < 3; i++) {
        std::cout << p1->ertek.egyutthato << " " << p1->ertek.kitevo << std::endl;
        std::cout << p1 << " " << p1->next << std::endl;
        p1 = p1->next;
    }

    /*for (int i = 0; i < a.size(); i++) {
        std::cout << a[i] << std::endl;
    }

    std::vector<int> b;
    for (int i = 0; i <= 3; i++) {
        b.push_back(2);
        b.push_back(3-i);
    }

    

    std::cout << std::endl << std::endl;

    Polynomial B = Polynomial(b);
    for (int i = 0; i < b.size(); i++) {
        std::cout << B.polinom.ertek.egyutthato << " " << B.polinom.ertek.kitevo << std::endl;
    }

    std::cout << std::endl << std::endl;

    Polynomial C = A - B;

    for (int i = 0; i < 3; i++) {
        std::cout << C.polinom.ertek.egyutthato << " " << C.polinom.ertek.kitevo << std::endl;
    }*/
}