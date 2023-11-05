#include "Somador.h"

#include <iostream>
#include <string>

using namespace std;

Somador::Somador() : CircuitoMISO(){

}

Somador::~Somador(){

}

Sinal* Somador::processar(Sinal* sinalIN1, Sinal* sinalIN2){
    // Somar casa com casa dos vetores
    // igual o EP1
    
   int comprimentoSoma;

    if ((sinalIN1->getComprimento()) >= (sinalIN2->getComprimento())){
        comprimentoSoma = (sinalIN2->getComprimento()); 
    }
    if ((sinalIN2->getComprimento()) > (sinalIN1->getComprimento())){
        comprimentoSoma = (sinalIN1->getComprimento());
    }
    
    double* sequenciaSomada = new double[comprimentoSoma]; // DELETADO EM:

    for (int i = 0; i < comprimentoSoma; i++){
        sequenciaSomada[i] = sinalIN1->getSequencia()[i] + sinalIN2->getSequencia()[i];
    }

    return new Sinal(sequenciaSomada, comprimentoSoma); // DELETADO EM:
} 


    
    



