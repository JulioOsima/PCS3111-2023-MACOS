#include "Item.h"

#include <iostream>

using namespace std;
// IMPLEMENTAR CONSTRUTOR

Item::Item(Produto* produto, int quantidade) :
produto(produto), quantidade(quantidade){
    // Não sei o que adicionar aqui
}

Produto* Item::getProduto() {
    return produto;
}

int Item::getQuantidade() {
    return quantidade;
}

double Item::calculaPrecoTotal() {
    return produto->getPreco() * quantidade;
}

void Item::setQuantidade(int quantidade) {
    this->quantidade = quantidade;
} 

void Item::imprimir() {
    cout << quantidade << " unidade(s) de ";
    produto->imprimir(); 
}

