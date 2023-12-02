#include "Amplificador.h"

Amplificador::Amplificador(double ganho):CircuitoSISO(), ganho(ganho){
// ...
}

Amplificador::~Amplificador(){
    delete[] sequenciaAmplificada;
    // ...
}

double Amplificador::getGanho(){
    return ganho;
}

void Amplificador::setGanho(double ganho){
    this->ganho = ganho;
}

Sinal* Amplificador::processar(Sinal* sinalIN){
    sequenciaAmplificada = new double[sinalIN->getComprimento()]; //DELETADO EM:
    for (int i = 0; i < sinalIN->getComprimento(); i++){
        sequenciaAmplificada[i] = ganho * (sinalIN->getSequencia()[i]); 
    } 
    Sinal *sinalAmplificado = new Sinal(sequenciaAmplificada, sinalIN->getComprimento());
    return sinalAmplificado;
}