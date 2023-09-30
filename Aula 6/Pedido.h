<<<<<<< HEAD
#ifndef PEDIDO_H
#define PEDIDO_H
#include "Produto.h"

class Pedido {
private:
    //Inclua aqui os atributos necessarios
     Produto** vetorDeProdutos;
     int quantidadeMaxima;
     int quantidadeDeProdutos;
     double valor;

public:
    Pedido(int quantidadeMaxima);
    virtual ~Pedido();

    bool adicionar(Produto *p);
    bool remover(Produto *p);
    Produto **getProdutos();
    int getQuantidadeDeProdutos();
    double getValor();
    void imprimir();
};
=======
#ifndef PEDIDO_H
#define PEDIDO_H
#include "Produto.h"

class Pedido {
private:
    //Inclua aqui os atributos necessarios
     Produto** vetorDeProdutos;
     int quantidadeMaxima;
     int quantidadeDeProdutos;
     double valor;

public:
    Pedido(int quantidadeMaxima);
    virtual ~Pedido();

    bool adicionar(Produto *p);
    bool remover(Produto *p);
    Produto **getProdutos();
    int getQuantidadeDeProdutos();
    double getValor();
    void imprimir();
};
>>>>>>> bdf4de33cd26a510d764ab76d420494f91803bc6
#endif