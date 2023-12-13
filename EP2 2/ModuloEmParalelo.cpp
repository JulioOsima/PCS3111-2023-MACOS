#include "ModuloEmParalelo.h"
#include <iostream>

using namespace std;

ModuloEmParalelo::ModuloEmParalelo():Modulo(){ 
}

ModuloEmParalelo::~ModuloEmParalelo(){   
    list<Sinal*>::iterator k = listaDeParalelos->begin();
    while (listaDeParalelos->empty() == false){
        Sinal *p = listaDeParalelos->front();
        listaDeParalelos->pop_front();
        delete p;
    }
    delete[] sequenciaDeSaida;
    delete listaDeParalelos;   
}

Sinal* ModuloEmParalelo::processar(Sinal* sinalIN){
    list<CircuitoSISO*>::iterator i = this->getCircuitos()->begin();
    bool listaVazia = true;

    while (i != this->getCircuitos()->end()){
        if ((*i) != nullptr){
            listaVazia = false;
            break;
        }   
        i++;
    }
    if (listaVazia == true){
    throw new logic_error("Não possui ciruitos SISO");
    return 0;
    }
   
    sequenciaDeSaida = new double[sinalIN->getComprimento()];
    Sinal* sinalDeSaida = new Sinal(sequenciaDeSaida, sinalIN->getComprimento());
    i = this->getCircuitos()->begin();

    listaDeParalelos = new list<Sinal*>();
    list<Sinal*>::iterator k = listaDeParalelos->begin();

    while (i != this->getCircuitos()->end()){
        listaDeParalelos->push_back((*i)->processar(sinalIN));
        i++;
    }
    Somador* sum = new Somador();
    k = listaDeParalelos->begin();
    sinalDeSaida = sum->processar((*k), (*k++));
    while (k != listaDeParalelos->end()){
        sinalDeSaida = sum->processar((*k), sinalDeSaida); // Funciona?
        k++;
    }

    delete sum;

    return sinalDeSaida;
}
   