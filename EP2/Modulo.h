#ifndef MODULO_H
#define MODULO_H

#include "CircuitoSISO.h"
#include "Sinal.h"
#include <iostream>
#include <string>
#include <list>

using namespace std;

class Modulo:public CircuitoSISO{
private:
    /* data */
  list<CircuitoSISO*>* lista;


public:
    Modulo();
    virtual ~Modulo();
    void adicionar(CircuitoSISO* circ);
    list<CircuitoSISO*>* getCircuitos();
};






#endif