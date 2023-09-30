<<<<<<< HEAD
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
=======
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
>>>>>>> bdf4de33cd26a510d764ab76d420494f91803bc6
}