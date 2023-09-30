//Faca os includes necessarios
//Implemente aqui os metodos
#include <iostream>
#include <string>
#include "Pedido.h"

using namespace std;

Pedido::Pedido(int quantidadeMaxima) {
    // implemente

    vetorDeProdutos = new Produto*[quantidadeMaxima]; //Pouco util colocar o vetordeprodutos com NULL em todas as posicoes 
    for (int i = 0; i < quantidadeMaxima; i++)
    {
        vetorDeProdutos[i] = NULL;
    }
    



}

Pedido::~Pedido() {
    // implemente
    delete[] vetorDeProdutos; //como fazer o delete do vetor?
}

bool Pedido::adicionar(Produto *p) {
    // implemente
    int posicao;
    for (int i = 0; i < quantidadeMaxima; i++)
    {
        if (p == vetorDeProdutos[i])
        {
            return false;
        }
        if (i == quantidadeMaxima)
        {
            return false;
        }
    }
    for (int j = 0; j < quantidadeMaxima; j++)
    {
        if (vetorDeProdutos[j] == NULL)
        {
            vetorDeProdutos[j] = p;
            return true;
        }
    }

    return false;
}

bool Pedido::remover(Produto *p) {
    // implemente

    int posicao;

    for (int i = 0; i < quantidadeMaxima; i++)
    {
        if (vetorDeProdutos[i] == p)
        {
            posicao = i;
            vetorDeProdutos[i] = NULL;
        }
    }
    if (posicao == (quantidadeMaxima - 1))
    {
        return true;
    }
    else{
        for (int j = posicao; j < quantidadeMaxima; j++)      
        {
            vetorDeProdutos[j] = vetorDeProdutos[j + 1];
        }
        return true;
    }

    return false;
}

Produto** Pedido::getProdutos() {
    for (int i = 0; i < quantidadeMaxima; i++)
    {
        if (vetorDeProdutos[i] != NULL)
        {
            return vetorDeProdutos;
        }
        
    }
    
    return nullptr;
}

int Pedido::getQuantidadeDeProdutos() {
    for (int i = 0; i < quantidadeMaxima; i++)
    {
        if (vetorDeProdutos[i] != NULL)
        {
            quantidadeDeProdutos++;
        }
        return quantidadeDeProdutos;
    }

    return -1;
}

double Pedido::getValor() {
    valor = 0;
    if (quantidadeDeProdutos > 0)
    {
         for (int i = 0; i < quantidadeMaxima; i++)
            {
                valor += (vetorDeProdutos[i]->getPreco());
               
            }
        return valor;
    }
 
    return -1;
}

void Pedido::imprimir() {
    cout << "Pedido com " << getQuantidadeDeProdutos() << " produto(s) - " << getValor() << " reais" << endl;
    for (int i = 0; i < getQuantidadeDeProdutos(); i++)
        getProdutos()[i]->imprimir();
    cout << endl;
}