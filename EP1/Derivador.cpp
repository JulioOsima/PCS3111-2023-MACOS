
#include "Derivador.h"
#include <iostream>
#include <string>

using namespace std;

Derivador::Derivador(){
// ...
}

Derivador::~Derivador(){
// ...
}

Sinal* Derivador::processar(Sinal* sinalIN){
    sequenciaOUT[0] = sequenciaIN[0];
    for (int i = 1; i < comprimentoIN - 1; i++)
    {
        sequenciaOUT[i] = (sequenciaIN[i + 1] - sequenciaIN[i]);
    }
    

}

