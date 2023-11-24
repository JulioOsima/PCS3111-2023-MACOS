#ifndef AMPLIFICADOR_H
#define AMPLIFICADOR_H

#include "CircuitoSISO.h"

#include <iostream>
#include <string>

using namespace std;

class Amplificador:public CircuitoSISO{
private:
    double ganho;
    Sinal* processar(Sinal* sinalIN);
public:
    Amplificador(double ganho);
    virtual ~Amplificador();
    void setGanho(double ganho);
    double getGanho();
};


#endif