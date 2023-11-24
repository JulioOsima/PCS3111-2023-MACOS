#ifndef DERIVADOR_H
#define DERIVADOR.H

#include "CircuitoSISO.h"
#include "Sinal.h"

#include <iostream>
#include <string>

using namespace std;

class Derivador:public CircuitoSISO{
private:
    /* data */

    double* sequenciaIN;
    double* sequenciaOUT;
    Sinal* processar(Sinal* sinalIN);

public:
    Derivador();
    virtual ~Derivador();    
};




#endif