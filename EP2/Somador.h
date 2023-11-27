#ifndef SOMADOR_H
#define SOMADOR_H

#include "CircuitoMISO.h"
#include <iostream>

using namespace std;

class Somador:public CircuitoMISO{
private:

// Adicionar alguma coisa aqui?

public:
    Somador();
    virtual ~Somador();
    Sinal* processar(Sinal* sinalIN1, Sinal* sinalIN2);
};


#endif