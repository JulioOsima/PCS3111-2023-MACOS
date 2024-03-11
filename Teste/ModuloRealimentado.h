#ifndef MODULOREALIMENTADO_H
#define MODULOREALIMENTADO_H

#include "Modulo.h"
#include "ModuloEmSerie.h"
#include "Somador.h"


class ModuloRealimentado:public Modulo{
private:
    
     ModuloEmSerie* moduloInterno;

public:
    ModuloRealimentado();
    virtual ~ModuloRealimentado();
    void adicionar(CircuitoSISO* circ);
    list<CircuitoSISO*>* getCircuitos();
    Sinal* processar(Sinal* sinalIN);
};



#endif