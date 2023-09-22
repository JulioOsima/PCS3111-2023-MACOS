#ifndef PEDIDO_H
#define PEDIDO_H

#include "Item.h"
#include "Produto.h"

class Pedido {
private:
    Item** itens;
    int quantidadeMaxima;
    int quantidade;

public:
    Pedido(int quantidadeMaxima);
    ~Pedido();

    Item** getItens();
    int getQuantidadeItens();
    int getQuantidadeMaximaItens();

    bool adicionar(Produto* produto, int quantidade);
    double calcularPrecoTotal();
};

#endif  // PEDIDO_H
