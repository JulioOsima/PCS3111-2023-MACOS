#ifndef MODULOEMSERIE_H
#define MODULOEMSERIE_H

#include "Modulo.h"
#include "Amplificador.h"
#include "Derivador.h"
#include "Integrador.h"
#include <stdexcept>

class ModuloEmSerie:public Modulo{
private:

public:
    ModuloEmSerie();
    virtual ~ModuloEmSerie();
    Sinal* processar(Sinal* sinalIN);
};

#endif