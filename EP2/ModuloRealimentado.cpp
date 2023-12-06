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

void ModuloRealimentado::adicionar(ModuloEmSerie* moduloEmSerie){
    listaDeMS->push_back(moduloEmSerie);
}

list<ModuloEmSerie*>* ModuloRealimentado::getCircuitos(){
    return listaDeMS;
}

Sinal* ModuloRealimentado::processar(Sinal* sinalIN){
// ALTERAR!!!!!!!!!!!!!!!!!
    Sinal* diferenca = nullptr;
    Sinal* saida = nullptr;
    Sinal* saidaInvertida = nullptr;

    double* sequenciaSaidaInvertida = new double[sinalIN->getComprimento()];
    
    double vInicial = 0;
    sequenciaSaidaInvertida[0] = 0;
    Sinal* sinalIntermediario = new Sinal(sinalIN->getSequencia()[0],1);
    diferenca = sinalIntermediario;

    list<ModuloEmSerie*>::iterator k = listaDeMS->begin();
    saida = (*k)->processar(diferenca);
    delete diferenca;

    Amplificador* inversor = new Amplificador(-1);
    Somador* somaEntradaESaidaInvertida = new Somador();
    for (int i = 1; i < sinalIN->getComprimento(); i++){
        sequenciaSaidaInvertida[i] = inversor->processar(saida)->getSequencia()[i - 1];
        saidaInvertida = new Sinal(sequenciaSaidaInvertida, i + 1);
        diferenca = somaEntradaESaidaInvertida->processar(sinalIN, saidaInvertida);
        delete saida;
        saida = new Sinal(diferenca->getSequencia(), diferenca->getComprimento());
        delete saidaInvertida;
        delete diferenca;
    }
    delete[] sequenciaSaidaInvertida;
    
    return saida;
}