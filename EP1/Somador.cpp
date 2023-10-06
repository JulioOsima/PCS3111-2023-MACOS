#include "Somador.h"
#include <iostream>
#include <string>

using namespace std;

Somador::Somador(){
// ...
}

Somador::~Somador(){
// ...
}

Sinal* Somador::processar(Sinal* sinalIN1, Sinal* sinalIN2){
    int comprimentoSoma;

    sequenciaIN1 = new double[sinalIN1->getComprimento()]; // DELETADO EM: Somador.cpp-L38
    sequenciaIN2 = new double[sinalIN2->getComprimento()]; // DELETADO EM: Somador.cpp-L39


    if ((sinalIN1->getComprimento()) > (sinalIN2->getComprimento()) || (sinalIN1->getComprimento()) == (sinalIN2->getComprimento()))
    {
        comprimentoSoma = (sinalIN2->getComprimento()); // comprimentoSoma = comprimento do sinal sinalIN1
    }
    if ((sinalIN2->getComprimento()) > (sinalIN1->getComprimento()))
    {
        comprimentoSoma = (sinalIN1->getComprimento());
    }
    
    double* sequenciaSomada = new double[comprimentoSoma]; // DELETADO EM:

    for (int i = 0; i < comprimentoSoma; i++)
    {
        sequenciaSomada[i] = sequenciaIN1[i] + sequenciaIN2[i];
    }
    
    delete[] sequenciaIN1;
    delete[] sequenciaIN2;

    return new Sinal(sequenciaSomada, comprimentoSoma); // DELETADO EM:
} 




