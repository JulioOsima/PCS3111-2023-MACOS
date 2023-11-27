#ifndef CIRCUITOSISO_H
#define CIRCUITOSISO_H

#include "Sinal.h"
#include "Circuito.h"
#include <iostream>

using namespace std;

class CircuitoSISO: public Circuito{ // A definicao de heranca está correta?
private:
    /* data */
    


public:
    CircuitoSISO();
    virtual ~CircuitoSISO();
    virtual Sinal* processar(Sinal* sinalIN) = 0; //tornar abstrato
    void imprimir();
};

#endif