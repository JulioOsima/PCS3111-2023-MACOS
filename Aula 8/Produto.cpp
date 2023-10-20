#include <iostream>
#include "Produto.h"

using namespace std;

Produto::Produto(string nome, double preco) : nome(nome), preco(preco) {
}

Produto::~Produto() {
}

double Produto::getPreco() {
    return preco;
}
string Produto::getNome() {
    return nome;
}

//void Produto::imprimir() { // Torne abstrato --------- Tenho q apagar?
//cout << getNome() << " - " << getPreco() << " reais" << endl;
//}