#ifndef MODULOREALIMENTADO_H
#define MODULOREALIMENTADO_H

#include "Modulo.h"
#include "ModuloEmSerie.h"


class ModuloRealimentado:public Modulo{
private:
    list<ModuloEmSerie*>* listaDeMS;

public:
    ModuloRealimentado();
    virtual ~ModuloRealimentado();
    void adicionar(ModuloEmSerie* moduloS);
    list<ModuloEmSerie*>* getCircuitos();
    Sinal* processar(Sinal* sinalIN);
};



#endif