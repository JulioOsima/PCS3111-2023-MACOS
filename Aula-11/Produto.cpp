#include "Produto.h"

#include <iostream>

using namespace std;

Produto::Produto(string nome, double preco) : nome(nome), preco(preco) {}

Produto::~Produto() {}

string Produto::getNome() {
    return nome;
}

double Produto::getPreco() {
    return preco;
}

void Produto::imprimir() {
    cout << nome << " - " << preco << " reais cada" << endl;
}
