#include "Pedido.h"
#include <iostream>
#include <string>

using namespace std;

void teste1() {

    Produto *p1 = new Produto;
    p1->setNome("Escova de dentes");
    p1->setPreco(5.49);
    p1->imprimir();
}

void teste2() {

    Produto *p2 = new Produto;
    p2->setNome("Agua");
    p2->setPreco(4.90);

    Produto *p3 = new Produto;
    p3->setNome("Desodorante");
    p3->setPreco(15.59);

    Pedido *ped1 = new Pedido;
    ped1->adicionar(p2);
    ped1->adicionar(p3);
    ped1->imprimir();
}

