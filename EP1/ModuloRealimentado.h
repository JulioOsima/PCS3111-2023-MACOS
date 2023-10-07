#ifndef MODULOREALIMENTADO_H
#define MODULOREALIMENTADO_H

#include "Sinal.h"
#include <iostream>
#include <string>

using namespace std;

class ModuloRealimentado{
private:
    // Definir como variaveis locais:
    double ganho;
    double *sequencia;
    double *saidaInvertida;
    Sinal* saidainvertidaS;

public:
    ModuloRealimentado(double ganho);
    virtual ~ModuloRealimentado();
    Sinal* processar(Sinal* sinalIN);
};

#endif