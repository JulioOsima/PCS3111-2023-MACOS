#include "Pedido.h"

#include <iostream>

using namespace std;

// IMPLEMENTE O CONSTRUTOR E O DESTRUTOR
Pedido::Pedido(int quantidadeMaxima) : 
quantidadeMaxima(quantidadeMaxima){
    quantidade = 0;
    //itens[quantidadeMaxima];
    itens = new Item*[quantidadeMaxima];
}

Pedido::~Pedido(){

    for (int i = 0; i < quantidade; i++)
    {
        delete itens[i];
    }
    
    delete[] itens;

    cout << "Pedido com " << this->quantidade << " item(ns) destruido " << endl;
}

//Final 

Item** Pedido::getItens() {
    return itens;
}

int Pedido::getQuantidadeItens() {
    return quantidade;
}

int Pedido::getQuantidadeMaximaItens() {
    return quantidadeMaxima;
}

bool Pedido::adicionar(Produto* produto, int quantidade) {
    if(this->quantidade >= quantidadeMaxima)
        return false;

    itens[this->quantidade] = new Item(produto, quantidade);
	this->quantidade++;
    return true;
}

double Pedido::calcularPrecoTotal() {
    double precoTotal = 0;
    for(int i = 0; i < quantidade; i++)
        precoTotal += itens[i]->calculaPrecoTotal();

    return precoTotal;
}
