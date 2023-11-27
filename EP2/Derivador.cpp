#include "Derivador.h"

Derivador::Derivador():CircuitoSISO(){
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
    Sinal *sinalDerivado = new Sinal(sequenciaOUT, sinalIN->getComprimento()); // Criar o atributo sinalDerivado em private para poder deletar ele no destrutor?
    delete[] sequenciaIN;
    delete[] sequenciaOUT;
    return sinalDerivado;
}