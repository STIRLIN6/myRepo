#include "Polynomial.hpp"

Polynomial::Polynomial (std::vector<int> x)
{
    //ElemLista e1 = ElemLista( Elem(x[0], x[1]) );
    ElemLista* e1 = new ElemLista( {x[0], x[1]} );
    
    for (int i = 2; i < x.size(); i += 2)
    {
        e1->follow(e1, new ElemLista( { x[i], x[i+1] } ) );
    }

    this->polinom->next = e1;
}

Polynomial::Polynomial() {}

Polynomial::~Polynomial() {

}

int Polynomial::degree()
{
    int degree = 0;

    ElemLista* popo = this->polinom;
    while (nullptr == popo->next)
    {
        if (popo->ertek.kitevo > degree) {
            degree = popo->ertek.kitevo;
        }
        popo = popo->next;
    }

    return degree;
}

Polynomial Polynomial::operator- (Polynomial& y) {

    ElemLista* c = this->polinom->copy();

    ElemLista* d = y.polinom;

    for (int i = 0; i < y.degree(); i++) {
        bool van = false;

        for (int j = 0; j < this->degree(); i++)
        {
            if (d->ertek.kitevo == c->ertek.kitevo) {
                van = true;
                c->ertek.egyutthato -= d->ertek.egyutthato;
            }
        }

        if (!van) {
            c->follow( c, new ElemLista( {0-d->ertek.egyutthato, d->ertek.kitevo } ) );
        }
    }

    Polynomial p = Polynomial();
    p.polinom = c;
    return p;

}