#include "Derivador.h"
#include <iostream>
#include <string>

using namespace std;

Derivador::Derivador(){
// ...
}

Derivador::~Derivador(){
// ...
}

Sinal* Derivador::processar(Sinal* sinalIN){
    sequenciaIN = new double[sinalIN->getComprimento()]; // DELETADO EM: Derivador.cpp-L28
    sequenciaOUT = new double[sinalIN->getComprimento()]; // DELETADO EM: Derivador.cpp-L29
    
    sequenciaOUT[0] = sequenciaIN[0];

    for (int i = 1; i < sinalIN->getComprimento(); i++){
        sequenciaOUT[i] = (sequenciaIN[i] - sequenciaIN[i - 1]);
    }

    delete[] sequenciaIN;
    delete[] sequenciaOUT;
    return new Sinal(sequenciaOUT, sinalIN->getComprimento()); // DELETADO EM:;
}

