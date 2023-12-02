#include "ModuloRealimentado.h"

ModuloRealimentado::ModuloRealimentado():Modulo(){
    listaDeMS = new list<ModuloEmSerie*>();
}

ModuloRealimentado::~ModuloRealimentado(){
    while (listaDeMS->empty() == false){
        ModuloEmSerie* p = listaDeMS->front();
        listaDeMS->pop_front();
        delete p;
    }
    delete listaDeMS;
}

void ModuloRealimentado::adicionar(ModuloEmSerie* moduloS){
    listaDeMS->push_back(moduloS);
}

list<ModuloEmSerie*>* ModuloRealimentado::getCircuitos(){
    return listaDeMS;
}

Sinal* ModuloRealimentado::processar(Sinal* sinalIN){
// ALTERAR!!!!!!!!!!!!!!!!!
    
    return sinalIN;
}