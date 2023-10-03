//Faca os includes necessarios

#include <iostream>
#include <string>
#include "Produto.h"
#include "Combo.h"

void teste1() {
    int i;

    Produto *p1 = new Produto("Pipoca Grande", 20);

    Produto *p2 = new Produto("Coca-Cola 1L", 15);

    //criar um vetor de produtos aqui?
    Produto** vetorDeProdutos;
    vetorDeProdutos = new Produto*[1];

    vetorDeProdutos[0] = p1;
    vetorDeProdutos[1] = p2;
    
    
    Combo *c1 = new Combo("Combo 2", vetorDeProdutos, 2, 0.2);
    c1->imprimir();

    delete c1;
}

void teste2() {
}

