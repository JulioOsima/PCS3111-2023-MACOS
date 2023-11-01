#ifndef CIRCUITOSISO_H
#define CIRCUITOSISO_H

#include "Sinal.h"
#include "Circuito.h"
#include <iostream>
#include <string>

using namespace std;

class CircuitoSISO:Circuito{ // A definicao de heranca está correta?
private:
    /* data */
    


public:
    CircuitoSISO();
    virtual ~CircuitoSISO();
    Sinal* processar(Sinal* sinalIN); //tornar abstrato
};

#endif