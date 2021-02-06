#include <vector>
#include "Lista.hpp"

class Polynomial
{
public:
    Polynomial(std::vector<int> x);
    Polynomial();
    ~Polynomial();
    
    ElemLista* polinom; //fejelem -> nem kerul bele semmi

    int degree();
    Polynomial operator- (Polynomial& y);
};