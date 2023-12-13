#ifndef ITEM_H
#define ITEM_H

#include "Produto.h"

class Item {
private:
    Produto* produto;
    int quantidade;

public:
    Item(Produto* produto, int quantidade);
    ~Item();

    Produto* getProduto();
    int getQuantidade();
    double calcularPrecoTotal();
    void setQuantidade(int quantidade);

    void imprimir();
};

#endif