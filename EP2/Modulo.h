#ifndef MODULO_H
#define MODULO_H

#include "CircuitoSISO.h"
#include "Sinal.h"
#include <iostream>
#include <string>
#include <stdexcept>

class Modulo:public CircuitoSISO{
private:
    /* data */
    void imprimir();

public:
    Modulo();
    virtual ~Modulo();
    void adicionar(CircuitoSISO* circ);
    list<CircuitoSISO*>* getCircuitos(); // pq o erro?
};






#endif