#include <iostream>
#include <string>

#include "Produto.h"
#include "Item.h"
#include "Pedido.h"


using namespace std;

void teste1() {
    Produto *p1 = new Produto("Cueca", 20.89);
    p1->imprimir();

    Item *i1 = new Item(p1, 5);
    i1->imprimir();

    delete i1;
    delete p1;
}

void teste2() {
    // IMPLEMENTE seguindo o enunciado
    Produto *p2 = new Produto("Absorvente", 10.40);
    Produto *p3 = new Produto("Pringles", 12.37);
    Produto *p4 = new Produto("Cookies", 5.39);

    Pedido *ped1 = new Pedido(4);
    ped1->adicionar(p2, 1);
    ped1->adicionar(p3, 1);
    ped1->adicionar(p4, 1);

    Pedido *ped2 = new Pedido(4);
    ped2->adicionar(p2, 1);
    ped2->adicionar(p4, 1);

    delete ped1;
    delete ped2;

    delete p2;
    delete p3;
    delete p4;

}