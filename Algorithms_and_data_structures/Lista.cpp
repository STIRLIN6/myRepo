#include "Lista.hpp"

ElemLista::ElemLista (Elem e) {
    this->ertek = e;
    this->next = nullptr;
}

ElemLista::ElemLista () {
    this->next = nullptr;
}

ElemLista* ElemLista::copy()
{
    ElemLista* result = new ElemLista(Elem(this->ertek.egyutthato,this->ertek.kitevo));
    ElemLista* res = result;
    ElemLista* el = this->next;
    while (nullptr != el)
    {
        res->next = new ElemLista(Elem(el->ertek.egyutthato,el->ertek.kitevo));
        res = res->next;
        el = el->next;
    }
    res->next = nullptr;

    return result;
}

void ElemLista::follow (ElemLista* p, ElemLista* q) {
    q->next = p->next;
    p->next = q;
}

ElemLista* ElemLista::out_next (ElemLista* p) {
    ElemLista* q = p->next;
    p->next = q->next;
    q->next = nullptr;

    return q;
}