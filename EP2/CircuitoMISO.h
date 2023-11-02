#ifndef CIRCUITOMISO_H
#define CIRCUITOMISO_H

#include "Sinal.h"
#include "Circuito.h"

#include <iostream>
#include <string>

using namespace std;

class CircuitoMISO:Circuito{
private:
    /* data */



public:
    CircuitoMISO(/* args */);
    virtual ~CircuitoMISO();
    virtual Sinal* processar(Sinal* sinaIN1, Sinal* sinalIN2) = 0;
};




#endif