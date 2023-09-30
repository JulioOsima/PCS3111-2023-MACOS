#include "Integrador.h"
#include <iostream>
#include <string>


using namespace std;


Integrador::Integrador(){
// ...
}

Integrador::~Integrador(){
// ...
}

Sinal* Integrador::processar(Sinal* sinalIN){
    sequenciaOUT[0] = sequenciaIN[0];

    for (int i = 1; i < comprimentoIN; i++)
    {
        sequenciaOUT[i] = sequenciaOUT[i - 1] + sequenciaIN[i];
    }
    
    return sinalOUT;
}