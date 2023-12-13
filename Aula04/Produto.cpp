#include "Produto.h"
#include <iostream>

using namespace std;

void Produto::setNome(string nome){
    this->nome = nome; 
}

string Produto::getNome(){
    return nome;
}

void Produto::setPreco(double preco){
    this->preco = preco;
}

double Produto::getPreco(){
    return preco;   
}

void Produto::imprimir() {
    cout << this->nome << " - " << this->preco << " reais" << endl;
}