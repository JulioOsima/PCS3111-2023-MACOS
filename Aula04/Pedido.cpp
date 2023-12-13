#include "Pedido.h"
#include <iostream>
#include <string>

using namespace std;

bool Pedido::adicionar(Produto* produto){
    int i;
    if (quantidade < 10){
        for (i = 0; i < MAXIMO_DE_PRODUTOS; i++){ // i vai até MAXIMO_DE_PRODUTOS pois o vetor começa no zero mas a quantidade começa em 1
            if (produto == produtos[i]){
                return false;
            }
        }
       produtos[quantidade] = produto; 
       quantidade++;
       return true;
    }
    
    return false;
}

double Pedido::getPrecoTotal(){
    int j;
    double precoTotal = 0;
    for (j = 0; j < quantidade; j++){
        precoTotal += (produtos[j]->getPreco());
    }
    return precoTotal;
}

void Pedido::imprimir(){
    int k;
    cout << "Pedido com " << quantidade << " produtos - " << getPrecoTotal() << " reais no total"  << endl;
    for (k = 0; k < quantidade; k++){
        produtos[k]->imprimir();
    }
}