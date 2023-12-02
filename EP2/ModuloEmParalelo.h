#ifndef MODULOEMPARALELO_H
#define MODULOEMPARALELO_H

#include "Modulo.h"
#include "Amplificador.h"
#include "Derivador.h"
#include "Integrador.h"
#include "Somador.h"

class ModuloEmParalelo:public Modulo{
private:
    list<Sinal*>* listaDeParalelos;
    double *sequenciaDeSaida;
public:
    ModuloEmParalelo();
    virtual ~ModuloEmParalelo();
    Sinal* processar(Sinal* sinalIN);
};

#endif