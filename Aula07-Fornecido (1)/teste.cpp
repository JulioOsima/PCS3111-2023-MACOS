//Faca os includes necessarios
#include "Pedido.h"
#include "ProdutoComDesconto.h"
#include <iostream>
#include <string>

using namespace std;

void teste1(){
    //Implemente o teste1
    Pedido *p1 = new Pedido(2);
    Produto *prod1 = new Produto("Bala de goma", 3.50);

    p1->adicionar(prod1);

    Produto *prod2 = new Produto("Chocolate", 5.20);
    p1->adicionar(prod2, 4);

    p1->imprimir();

    delete prod1;
    delete prod2;
    delete p1;


}

void teste2(){
    //Implemente o teste2
    Pedido *p1 = new Pedido(2);
    Produto *prod1 = new Produto("Linguica", 20.90);

    p1->adicionar(prod1, 2);

    Produto *prodD1 = new ProdutoComDesconto("Picanha", 70.49, 0.1); // como armazenar como um ponteiro do tipo produto?
    
    p1->adicionar(prodD1);
    p1->imprimir();

    delete prod1;
    delete prodD1;
    delete p1;


}

void teste3() {
    //Implemente o teste3

    Pedido *p1 = new Pedido(2);
 
    p1->imprimir();


}

