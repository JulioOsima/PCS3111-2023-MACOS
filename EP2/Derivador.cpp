#include "Derivador.h"

Derivador::Derivador(){

// Definir como classe filha

}

Derivador::~Derivador(){

}

Sinal* Derivador::processar(Sinal* sinalIN){
    sequenciaIN = new double[sinalIN->getComprimento()]; // DELETADO EM: 
    sequenciaOUT = new double[sinalIN->getComprimento()]; // DELETADO EM:
    
    sequenciaOUT[0] = sequenciaIN[0];

    for (int i = 1; i < sinalIN->getComprimento(); i++){
        sequenciaOUT[i] = (sequenciaIN[i] - sequenciaIN[i - 1]);
    }

    delete[] sequenciaIN;
    delete[] sequenciaOUT;
    return new Sinal(sequenciaOUT, sinalIN->getComprimento()); // DELETADO EM: 

}