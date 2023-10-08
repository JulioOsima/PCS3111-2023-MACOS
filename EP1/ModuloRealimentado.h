#ifndef MODULOREALIMENTADO_H
#define MODULOREALIMENTADO_H

#include "Sinal.h"
#include <iostream>
#include <string>

using namespace std;

class ModuloRealimentado{
private:
    double ganho;
    double *vetorSaida;
    Sinal* saida;
public:
    ModuloRealimentado(double ganho);
    virtual ~ModuloRealimentado();
    Sinal* processar(Sinal* sinalIN);
};

#endif