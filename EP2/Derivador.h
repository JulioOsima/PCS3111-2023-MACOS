#ifndef DERIVADOR_H
#define DERIVADOR.H

#include "CircuitoSISO.h"
#include "Sinal.h"
#include <iostream>

using namespace std;

class Derivador:public CircuitoSISO{
private:
    /* data */

    double* sequenciaIN;
    double* sequenciaOUT;
    

public:
    Derivador();
    virtual ~Derivador();    
    Sinal* processar(Sinal* sinalIN);
};




#endif