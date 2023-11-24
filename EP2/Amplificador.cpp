#include "Amplificador.h"

#include <iostream>
#include <string>

using namespace std;

Amplificador::Amplificador(double ganho):CircuitoSISO(), ganho(ganho){
// ...
}

Amplificador::~Amplificador(){
// ...
}

double Amplificador::getGanho(){
    return ganho;
}

void Amplificador::setGanho(double ganho){
    this->ganho = ganho;
}

Sinal* Amplificador::processar(Sinal* sinalIN){
    double* sequenciaAmplificada = new double[sinalIN->getComprimento()]; //DELETADO EM:

    for (int i = 0; i < sinalIN->getComprimento(); i++){
        sequenciaAmplificada[i] = ganho * (sinalIN->getSequencia()[i]); 
    } 
    return new Sinal(sequenciaAmplificada, sinalIN->getComprimento()); // DELETADO EM:
}