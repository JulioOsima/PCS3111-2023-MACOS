#ifndef PEDIDO_H
#define PEDIDO_H
#include "Produto.h"
#include "Item.h"
#include "ProdutoComDesconto.h"
//Faca os includes necessarios a medida em que faz os exercicios

class Pedido {
public:
    //Declare os metodos pedidos no enunciado
    Pedido(int quantidadeMaxima);
    ~Pedido();

    bool adicionar(Produto *produto);
    bool adicionar(Produto *produto, int quantidade); 

    Item** getItens();
    int getQuantidadeItens();
    ProdutoComDesconto** getProdutosComDesconto(int& quantidade);
    
    double calcularPrecoTotal();
    void imprimir();
private:
    Item** itens;
    int quantidadeMaxima;
    int quantidade;
    ProdutoComDesconto** produtosComDesconto;
};

#endif // PEDIDO_H
