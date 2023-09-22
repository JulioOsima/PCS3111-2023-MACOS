#include "Produto.h"

#include <iostream>

using namespace std;

// IMPLEMENTAR CONSTRUTOR

Produto::Produto(string nome, double preco){
    this->nome = nome;
    this->preco = preco;
    
    // Tbm n sei o que colocar aqui. Colocar "nome(nome)"faz com que o atributi nome receba o parâmetro nome?"

}

Produto::~Produto(){
    cout << "Produto " << this->nome << " destruido" << endl;
}

// Final

string Produto::getNome() {
    return nome;
}

double Produto::getPreco() {
    return preco;
}

void Produto::imprimir(){
    cout << nome << " - " << preco << " reais cada" << endl;
}

