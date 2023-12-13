#include "Locacao.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Locacao::Locacao(string endereco, double preco, int vencimento) {
    this->endereco = endereco;

    if (preco <= 0){
        throw new invalid_argument("Preco informado invalido");
    }
    this->preco = preco;
    if (vencimento < 1 || vencimento > 31){
        throw new invalid_argument("Vencimento deve ser um dia valido");
    }
    this->vencimento = vencimento;
}

Locacao::~Locacao() {}

string Locacao::getEndereco() {
    return endereco;
}

double Locacao::getPreco() {
    return preco;
}

void Locacao::setPreco(double novo) {
    if (novo <= 0){
        throw new invalid_argument("Preco informado invalido");
    }
    this->preco = novo;
}

int Locacao::getVencimento() {
    return vencimento;
}