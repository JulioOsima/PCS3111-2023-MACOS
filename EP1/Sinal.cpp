#include "Sinal.h"  
#include "Grafico.h"
#include <iostream>
#include <string>

using namespace std;

// OBS:  

Sinal::Sinal(double *sequencia, int comprimento) :
    sequencia(sequencia), comprimento(comprimento){

    for (int i = 0; i < comprimento; i++)
    {
        sequenciaCopia[i] = sequencia[i];
    }
}

Sinal::~Sinal(){
// ...
}

double* Sinal::getSequencia(){
    return sequencia;
}

int Sinal::getComprimento(){
    return comprimento;
}

void Sinal::imprimir(string nomeDoSinal){
    Grafico *graficoSinal = new Grafico(nomeDoSinal, sequenciaCopia, comprimento); //
    graficoSinal->plot();
    
}






