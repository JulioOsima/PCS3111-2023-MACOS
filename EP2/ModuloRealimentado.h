#ifndef MODULOREALIMENTADO_H
#define MODULOREALIMENTADO_H

#include "Modulo.h"
#include "ModuloEmSerie.h"


class ModuloRealimentado:public Modulo{
private:
    /* data */
public:
    ModuloRealimentado();
    virtual ~ModuloRealimentado();
    Sinal* processar(Sinal* sinalIN);
};



#endif