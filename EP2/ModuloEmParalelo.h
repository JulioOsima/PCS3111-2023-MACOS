#ifndef MODULOEMPARALELO_H
#define MODULOEMPARALELO_H

#include "Modulo.h"
#include "Amplificador.h"
#include "Derivador.h"
#include "Integrador.h"
#include <stdexcept>

class ModuloEmParalelo:public Modulo{
private:
    /* data */
    list<Sinal*>* listaDeParalelos;
public:
    ModuloEmParalelo();
    virtual ~ModuloEmParalelo();
    Sinal* processar(Sinal* sinalIN);
};






#endif