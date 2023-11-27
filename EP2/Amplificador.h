#ifndef AMPLIFICADOR_H
#define AMPLIFICADOR_H

#include "CircuitoSISO.h"
#include <iostream>

using namespace std;

class Amplificador:public CircuitoSISO{
private:
    double ganho;
    
public:
    Amplificador(double ganho);
    virtual ~Amplificador();
    void setGanho(double ganho);
    double getGanho();
    Sinal* processar(Sinal* sinalIN);
};


#endif