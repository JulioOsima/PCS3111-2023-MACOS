#include "ModuloRealimentado.h"
#include <iostream>
#include <string>

using namespace std;

ModuloRealimentado::ModuloRealimentado(double ganho) : 
ganho(ganho){
// ... 
}

ModuloRealimentado::~ModuloRealimentado(){
// ...
}

Sinal* ModuloRealimentado::processar(Sinal* sinalIN){
// ... adicionar o resto do metodo
    // Criar um vetor 
    sequencia = new double[(sinalIN->getComprimento())];
    saidaInvertida[0] = 0;

    for (int i = 1; i < (sinalIN->getComprimento()); i++)
    {
        saidaInvertida[i] = ((((sinalIN->getSequencia())[i - 1]) - saidaInvertida[i - 1]) * ganho) + saidaInvertida[i - 1];
    }
    
    return new Sinal(sequencia, (sinalIN->getComprimento()));
}
