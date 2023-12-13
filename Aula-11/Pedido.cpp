#include "Pedido.h"


#include <iostream>
#include <stdexcept>

using namespace std;

Pedido::Pedido(){
    pedido = new list<Item*>();
}

Pedido::~Pedido() {
    cout << "Pedido com " << pedido->size() << " item(ns) destruido" << endl;
    while (pedido->empty() == false){
       Item *p = pedido->front();
       pedido->pop_front();
       delete p;
    }
    delete pedido;
    
    /*cout << "Pedido com " << quantidade << " item(ns) destruido" << endl;
    for (int i = 0; i < quantidade; ++i) delete itens[i];
    delete[] itens;*/
}

void Pedido::adicionar(Produto* produto, int quantidade) {
   
        list<Item*>::iterator i = pedido->begin();
        while (i != pedido->end()){
            if ((*i)->getProduto() == produto){
                throw new invalid_argument("Item ja existe");
            }
            i++;
        }
        pedido->push_back(new Item(produto, quantidade));
   
   /* if (this->quantidade >= quantidadeMaxima) throw new overflow_error("Pedido cheio");
    for (int i = 0; i < quantidade; i++)
        if (produto == itens[i]->getProduto()) throw new invalid_argument("Produto ja existente");

    itens[this->quantidade++] = new Item(produto, quantidade);*/
}

list<Item*>* Pedido::getItens(){
    return pedido;
}

void Pedido::imprimir() {
    cout << "Pedido - " << pedido->size() << " item(ns)" << endl;
    list<Item*>::iterator i = pedido->begin();
    while (i != pedido->end()){
        (*i)->imprimir();
        i++;
    }
    

    /*for (int i = 0; i < quantidade; i++) itens[i]->imprimir();*/
}