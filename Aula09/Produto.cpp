//Faca os includes necessarios
#include <stdexcept>

#include "Produto.h"
#include "ProdutoIndisponivel.h"

#include <iostream>

using namespace std;

Produto::Produto(string nome, double preco) : nome(nome), preco(preco), disponivel(true) {
    // Altere conforme o enunciado
    if (preco <= 0)
    {
        throw new invalid_argument("Preco invalido");
    }
}

Produto::~Produto() {
    cout << "Produto " << nome << " destruido" << endl;
}

string Produto::getNome() {
    return nome;
}

double Produto::getPreco() {
    // Altere conforme o enunciado

    if (this->getDisponivel() == false){
        throw new ProdutoIndisponivel("Produto indisponivel");
    }
    
    return preco;
}

bool Produto::getDisponivel() {
    return disponivel;
}

void Produto::setDisponivel(bool disponivel) {
    this->disponivel = disponivel;
}

void Produto::imprimir(){
    cout << nome << " - " << getPreco() << " reais cada" << endl;
}
