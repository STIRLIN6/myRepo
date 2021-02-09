#pragma once

#include <vector>

struct Elem {
    int egyutthato;
    int kitevo;
    Elem(int a, int b) : egyutthato(a), kitevo(b) {}
    Elem() {}
};

class ElemLista
{
public:
    ElemLista (Elem e);
    ElemLista();
    ElemLista* next;
    Elem ertek;

    ElemLista* copy();

    void follow (ElemLista* p, ElemLista* q);

    ElemLista* out_next (ElemLista* p);
};