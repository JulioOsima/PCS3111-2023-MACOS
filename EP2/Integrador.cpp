#include "Integrador.h"

Integrador::Integrador():CircuitoSISO(){
}

Integrador::~Integrador(){
}

Sinal* Integrador::processar(Sinal* sinalIN){
    sequenciaOUT = new double[sinalIN->getComprimento()]; // DELETADO EM:
    sequenciaOUT[0] = (sinalIN->getSequencia()[0]);

    for (int i = 1; i < (sinalIN->getComprimento()); i++){
        sequenciaOUT[i] = sequenciaOUT[i - 1] + (sinalIN->getSequencia()[i]);
    }
    Sinal *sinalIntegrado = new Sinal(sequenciaOUT, sinalIN->getComprimento());// Criar o atributo sinalIntegrado em private para poder deletar ele no destrutor?
    delete[] sequenciaOUT;
    return sinalIntegrado;

}
