#include "Pedido.h"
#include <iostream>
#include <string>

//Faca os includes necessarios e implemente os metodos pedidos no enunciado

using namespace std;

Pedido::Pedido(int quantidadeMaxima) : itens(new Item*[quantidadeMaxima]), quantidadeMaxima(quantidadeMaxima), quantidade(0) {}

Pedido::~Pedido() {
    cout << "Pedido com " << quantidade << " item(ns) destruido" << endl;
    for (int i = 0; i < quantidade; ++i) delete itens[i];
    delete[] itens;
}

Item** Pedido::getItens() {
    return itens;
}

int Pedido::getQuantidadeItens() {
    return quantidade;
}


bool Pedido::adicionar(Produto* produto, int quantidade) {
    if (this->quantidade >= quantidadeMaxima)
        return false;
    
    itens[this->quantidade++] = new Item(produto, quantidade);
    return true;
}

bool Pedido::adicionar(Produto *produto){
    if (this->quantidade >= quantidadeMaxima) // this->quantidade se refere a quantidade de itens do vetor n a quantidade do produto
    {
        return false;
    }
    itens[this->quantidade++] = new Item(produto, 1); // Vetor de valores do tipo Item com tamanho = quantidade + 1
    
    return true;
}

double Pedido::calcularPrecoTotal() {
    double precoTotal = 0;
    for (int i = 0; i < quantidade; i++)
        precoTotal += itens[i]->calculaPrecoTotal();

    return precoTotal;
}

void Pedido::imprimir(){
    cout << "Pedido com " << quantidade << " item(ns)" << endl;
    for (int i = 0; i < quantidade; i++)
    {
        itens[i]->imprimir(); 
    }
    
}

ProdutoComDesconto** Pedido::getProdutosComDesconto(int& quantidade){
    int aux;
    
    produtosComDesconto = new ProdutoComDesconto*[quantidadeMaxima];
    for (int i = 0; i < quantidade; i++)
    {
        if (dynamic_cast<ProdutoComDesconto*>((itens[i])->getProduto()) != NULL)
        {
           produtosComDesconto[i] = dynamic_cast<ProdutoComDesconto*>((itens[i])->getProduto());
           aux = i;
        }
        produtosComDesconto[i] = NULL;
    }
    int aux2 = 0;
    
    for (int j = 0; j < aux; j++)
    {
        if (produtosComDesconto[j] != NULL)
        {
            produtosComDesconto[aux2] = produtosComDesconto[j];
            aux2++;
        }
    }
    if (aux2 < 1)
    {
        return NULL;
    }
    
    return produtosComDesconto;




    


}