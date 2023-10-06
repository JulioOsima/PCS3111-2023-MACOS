#include "Sinal.h"  
#include "Grafico.h"
#include <iostream>
#include <string>

using namespace std;

Sinal::Sinal(double *sequencia, int comprimento) :comprimento(comprimento){
    this->sequencia = new double[comprimento]; // DELETADO EM: Sinal.cpp-L19
    for (int i = 0; i < comprimento; i++)
    {
        this->sequencia[i] = sequencia[i];
    }
}

Sinal::~Sinal(){
    delete[] sequencia;
}

double* Sinal::getSequencia(){
    return sequencia;
}

int Sinal::getComprimento(){
    return comprimento;
}

void Sinal::imprimir(string nomeDoSinal){
    Grafico *graficoSinal = new Grafico(nomeDoSinal, sequencia, comprimento); // É a última coisa a ser feita, preciso deletar?
    graficoSinal->plot();
    delete graficoSinal;
    
    
}






