#include <iostream>
#include "Produto.h"
#include "ProdutoIndisponivel.h"
#include "Pedido.h"


void teste1(){
    /*Implemente conforme o enunciado*/
    
    try
    {
         Produto *prod1 = new Produto("agua", -1);
    }
    catch(invalid_argument *e)
    {
        cout << "Erro: " << e->what() << endl;
        delete e; 
    }
}

void teste2(){
    /*Implemente conforme o enunciado*/

    try
    {
        Produto *prod2 = new Produto("Gatorade", 7.50);
        prod2->imprimir();
        prod2->setDisponivel(false);
        prod2->getPreco();


    }
    catch(ProdutoIndisponivel *e){
        cout << "Erro: " << e->what() << endl;
        delete e;
    }

   /* catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }*/
    
}

void teste3(){
   /*Implemente conforme o enunciado*/   

    Pedido *ped1 = new Pedido(4);
    Produto *prod1 = new Produto("Cerveja", 4.35);
    Produto *prod2 = new Produto("Bis", 3.90);
    Produto *prod3 = new Produto("Frigideira", 80.79);
    Produto *prod4 = new Produto("Vassoura", 30.50);

    ped1->adicionar(prod1, 5);
    ped1->adicionar(prod2, 2);
    ped1->adicionar(prod3, 1);
    ped1->adicionar(prod4, 1);

    cout << ped1->calcularPrecoTotal() << endl;

    prod1->setDisponivel(false);
    prod3->setDisponivel(false);

    cout << ped1->calcularPrecoTotal() << endl;

    prod2->setDisponivel(false);
    prod4->setDisponivel(false);

    cout << ped1->calcularPrecoTotal() << endl;




}
