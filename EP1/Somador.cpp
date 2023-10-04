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
    if (comprimentoIN1 > comprimentoIN2 || comprimentoIN1 == comprimentoIN2)
    {
        comprimentoSoma = comprimentoIN2;
    }
    if (comprimentoIN2 > comprimentoIN1)
    {
        comprimentoSoma = comprimentoIN1;
    }
    
    double* sequenciaSomada = new double[comprimentoSoma]; // Verificar se a relação comprimento e posição do vetor -> sequenciaSomada tem "comprimentoSoma" casas e vai de 0 à "comprimentoSoma" - 1 DELETADO EM:

    for (int i = 0; i < comprimentoSoma; i++)
    {
        sequenciaSomada[i] = sequenciaIN1[i] + sequenciaIN2[i];
    }
    
    Sinal* soma = new Sinal(sequenciaSomada, comprimentoSoma); // DELETADO EM:

    return soma;
} 




