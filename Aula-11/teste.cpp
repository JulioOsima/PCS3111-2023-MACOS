//Faca os includes necessarios

#include "Combo.h"
#include "Pedido.h"
#include <stdexcept>

void teste1() {
    //Implemente segundo o enunciado

    Combo* c1 = new Combo("Burger e bebida");
    Produto* p1 = new Produto("X-Bacon", 24.99);
    try{
        c1->adicionar(p1);
    }
    catch(invalid_argument *e){
    }

    Produto* p2 = new Produto("Coca-Cola Lata",4.49);
    try{
        c1->adicionar(p2);
    }
    catch(invalid_argument *e){
    }
    
    c1->imprimir();
    delete c1;
    delete p1;
    delete p2;


}

void teste2() {
    Pedido* ped1 = new Pedido();

    Combo* c1 = new Combo("Burger e bebida");
    Produto* p1 = new Produto("X-Bacon", 24.99);
    c1->adicionar(p1);
    Produto* p2 = new Produto("Coca-Cola Lata",4.49);
    c1->adicionar(p2);

    try{
        ped1->adicionar(c1, 2);
    }
    catch(invalid_argument *e){
    }
    
    Produto* p3 = new Produto("Sundae", 7.85);

    try{
        ped1->adicionar(p3, 2);
    }
    catch(invalid_argument *e){
    } 

    ped1->imprimir();

    delete ped1;
    delete c1;
    delete p1;
    delete p2;
    delete p3;


    //Implemente segundo o enunciado
}