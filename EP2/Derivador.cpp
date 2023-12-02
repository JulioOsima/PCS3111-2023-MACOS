#include "Derivador.h"

Derivador::Derivador():CircuitoSISO(){
}

Derivador::~Derivador(){
    delete[] sequenciaOUT;
}

Sinal* Derivador::processar(Sinal* sinalIN){
    sequenciaOUT = new double[sinalIN->getComprimento()]; // DELETADO EM:
    sequenciaOUT[0] = sinalIN->getSequencia()[0];

    for (int i = 1; i < sinalIN->getComprimento(); i++){
        sequenciaOUT[i] = (sinalIN->getSequencia()[i] - sinalIN->getSequencia()[i - 1]);
    }
    Sinal *sinalDerivado = new Sinal(sequenciaOUT, sinalIN->getComprimento()); // Criar o atributo sinalDerivado em private para poder deletar ele no destrutor?
    return sinalDerivado;
}