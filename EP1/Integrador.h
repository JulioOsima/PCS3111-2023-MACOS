#ifndef INTEGRADOR_H
#define INTEGRADOR_H

#include "Sinal.h"
#include <iostream>
#include <string>

using namespace std;

class Integrador{
private:
    double* sequenciaOUT;
public:
    Integrador();
    virtual ~Integrador();
    Sinal* processar(Sinal* sinalIN);
};

#endif