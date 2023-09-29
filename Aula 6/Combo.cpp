//Faca os includes necessarios
//Implemente aqui os metodos


#include "Combo.h"
#include <iostream>
#include <string>

using namespace std;

Combo::Combo(string nome, Produto **p, int quantidadeDeProdutos, double desconto) : Produto(nome, 0),
nome(nome), p(p), quantidadeDeProdutos(quantidadeDeProdutos), desconto(desconto){
    for (int i = 0; i < quantidadeDeProdutos; i++)
    {
        preco += (p[i]->getPreco());
    }
    preco = preco * (1 - desconto);
}

Combo::~Combo(){

}

Produto** Combo::getProdutos(){
    return p; // Retornar o produto no vetor **p?

}

int Combo::getQuantidadeDeProdutos(){
    return quantidadeDeProdutos;
}

double Combo::getDesconto(){
    return desconto;
}

void Combo::imprimir(){
    cout << "Produto: " << nome << " - " << getPreco() << " reais" << endl;
}

//    ((p[0]->getPreco() + p[1]->getPreco()) * (1 - desconto))