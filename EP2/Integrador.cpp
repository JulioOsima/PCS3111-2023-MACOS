#include "Integrador.h"

Integrador::Integrador():CircuitoSISO(){

//

}

Integrador::~Integrador(){

}

Sinal* Integrador::processar(Sinal* sinalIN){
    sequenciaOUT = new double[sinalIN->getComprimento()]; // DELETADO EM:
    sequenciaOUT[0] = (sinalIN->getSequencia()[0]);

    for (int i = 1; i < (sinalIN->getComprimento()); i++){
        sequenciaOUT[i] = sequenciaOUT[i - 1] + (sinalIN->getSequencia()[i]);
    }
    
    return new Sinal(sequenciaOUT, (sinalIN->getComprimento())); // DELETADO EM:

}
