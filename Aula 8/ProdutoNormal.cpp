#include "ProdutoNormal.h"
#include <iostream>
#include <string>

using namespace std;

// Faca os includes necessarios
//implemente os métodos

ProdutoNormal::ProdutoNormal(string nome, double preco):Produto(nome, preco){
}

ProdutoNormal::~ProdutoNormal(){
    cout << "Produto " << this->nome << " destruido" << endl;
}

void ProdutoNormal::imprimir(){
    cout << this->getNome() << " - " << this->getPreco() << " reais" << endl;
}