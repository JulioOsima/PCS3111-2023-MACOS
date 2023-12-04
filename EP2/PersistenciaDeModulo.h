#ifndef PERSISTENCIADEMODULO_H
#define PERSISTENCIADEMODULO_H

#include "Modulo.h"
#include "ModuloEmSerie.h"
#include "ModuloEmParalelo.h"
#include "ModuloRealimentado.h"

#include <fstream>
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class PersistenciaDeModulo{
private:
    string nomeDoArquivo;
    list<Modulo*>* listaDeModulos;
    string verificaModulo(CircuitoSISO* circuito);
    
public:
    PersistenciaDeModulo(string nomeDoArquivo);
    virtual ~PersistenciaDeModulo();
    void salvarEmAquivo(Modulo* mod);
    Modulo* lerArquivo();
};

#endif