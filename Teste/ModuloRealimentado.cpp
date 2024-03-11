#include "ModuloRealimentado.h"

ModuloRealimentado::ModuloRealimentado():Modulo(){
    //listaDeMS = new list<ModuloEmSerie*>();
     moduloInterno = new ModuloEmSerie();
}

ModuloRealimentado::~ModuloRealimentado(){
    while (moduloInterno->getCircuitos()->empty() == false){
        CircuitoSISO* p = moduloInterno->getCircuitos()->front();
        moduloInterno->getCircuitos()->pop_front();
        delete p;
    }
    delete moduloInterno;
}

void ModuloRealimentado::adicionar(CircuitoSISO* circ){
    moduloInterno->adicionar(circ);
}

list<CircuitoSISO*>* ModuloRealimentado::getCircuitos(){

    return moduloInterno->getCircuitos();
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

    //list<ModuloEmSerie*>::iterator k = listaDeMS->begin();
    saida = moduloInterno->processar(diferenca);
    
    delete diferenca;

    Amplificador* inversor = new Amplificador(-1);
    Somador* somaEntradaESaidaInvertida = new Somador();
    for (int i = 1; i < sinalIN->getComprimento(); i++){
        sequenciaSaidaInvertida[i] = inversor->processar(saida)->getSequencia()[i - 1];
        saidaInvertida = new Sinal(sequenciaSaidaInvertida, i + 1);
        diferenca = somaEntradaESaidaInvertida->processar(sinalIN, saidaInvertida);
        delete saida;
        saida = new Sinal(moduloInterno->processar(diferenca)->getSequencia(), moduloInterno->processar(diferenca)->getComprimento());
        delete saidaInvertida;
        delete diferenca;
    }
    delete[] sequenciaSaidaInvertida;
    
    return saida;
}