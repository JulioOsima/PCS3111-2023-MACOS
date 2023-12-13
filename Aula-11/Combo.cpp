#include "Combo.h"
#include <stdexcept>
#include <iostream>
#include <vector>

using namespace std;

Combo::Combo(string nome) : Produto(nome, 0){
    combo = new vector<Produto*>();
}

Combo::~Combo() {
    delete combo; 
}

void Combo::adicionar(Produto *p) {
        for (int i = 0; i < combo->size(); i++){
            if (combo->at(i) == p){
                throw new invalid_argument("Produto já está no combo");
            }
        }
        combo->push_back(p);
    }

    



    /*if (quantidade >= quantidadeMaxima) throw new overflow_error("Combo cheio");
    for (int i = 0; i < quantidade; i++)
        if (produtos[i] == p) throw new invalid_argument("Produto ja existe");
    produtos[quantidade++] = p;*/


double Combo::getPreco() {
    double soma = 0;
    for (int i = 0; i < combo->size(); i++){
        soma += (combo->at(i))->getPreco();
    }
    return soma;
    
    
    /*double soma = 0;
    for (int i = 0; i < quantidadeMaxima; i++)
        soma += produtos[i]->getPreco();

    return soma*/
}

vector <Produto*>* Combo::getProdutos(){
    return combo;
}

void Combo::imprimir() {
    cout << nome << " - " << getPreco() << " reais cada" << endl;
    for (int i = 0; i < combo->size(); i++){
        combo->at(i)->imprimir();
    }
    

    /*cout << nome << " - " << getPreco() << " reais cada" << endl;
    for (int i = 0; i < quantidade; i++)
        produtos[i]->imprimir();*/
}