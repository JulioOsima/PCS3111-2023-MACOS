#include "Amplificador.h"
#include <iostream>
#include <string>

using namespace std;

Amplificador::Amplificador(double ganho):
ganho(ganho){
// ...
}

Amplificador::~Amplificador(){
// ...
}

Sinal* Amplificador::processar(Sinal* sinalIN){

    Sinal *s1 = new Sinal(sequenciaAmplificada, comprimentoSA); // DELETADO EM:
    for (int i = 0; i < comprimentoSA; i++)
    {
        sequenciaAmplificada[i] = ((ganho * (sinalIN->getSequencia())[i])); // N tenho certeza se funciona, "sinalIN->getSequencia" deve retornar um vetor de double, entao so coloquei o indice do lado
    }   
}

void Amplificador::setGanho(double ganho){
    this->ganho = ganho;
} 

double Amplificador::getGanho(){
    return ganho;
}
