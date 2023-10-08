#ifndef SOMADOR_H
#define SOMADOR_H
#include "Sinal.h"
#include <iostream>
#include <string>


using namespace std;

class Somador{
private:
    double* sequenciaIN1;
    double* sequenciaIN2;

public:
    Somador();
    virtual ~Somador();
    Sinal* processar(Sinal* sinalIN1, Sinal* sinalIN2);
};

#endif


