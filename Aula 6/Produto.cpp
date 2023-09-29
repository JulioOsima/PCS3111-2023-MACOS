#include "Produto.h"

Produto::Produto(string nome, double preco) {
    this->nome = nome;
    this->preco = preco;
}

string Produto::getNome() {
    return nome;
}

double Produto::getPreco() {
    return preco;
}

void Produto::imprimir() {
    cout << "Produto: " << getNome() << " - " << getPreco() << " reais" << endl;
}

Produto::~Produto() {
}