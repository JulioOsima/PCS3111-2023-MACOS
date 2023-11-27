#ifndef PEDIDO_H
#define PEDIDO_H

#include "Produto.h"
#include "Item.h"
#include <list>

//Modifique a classe Pedido para que seus itens estejam em um container list

class Pedido {
private:
    list<Item*>* pedido;
    int quantidadeMaxima;
    int quantidade;
public:
    Pedido();
    virtual ~Pedido();
    
    void adicionar(Produto *produto, int quantidade); 
    list<Item*>* getItens();

    void imprimir(); 
};

#endif