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
    delete[] vetorSaida;
    delete saida;

}

Sinal* ModuloRealimentado::processar(Sinal* sinalIN){
// ... adicionar o resto do metodo
    // Criar um vetor 
    vetorSaida = new double[(sinalIN->getComprimento())];
    vetorSaida[0] = ganho * sinalIN->getSequencia()[0];
    
    for (int i = 1; i < (sinalIN->getComprimento()); i++)
    {
        vetorSaida[i] = vetorSaida[i - 1] + (ganho * (sinalIN->getSequencia()[i] - vetorSaida[i - 1]));
    }

    saida = new Sinal(vetorSaida, (sinalIN->getComprimento()));

    return saida;
}
