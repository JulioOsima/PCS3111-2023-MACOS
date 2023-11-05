#ifndef PERSISTENCIADEMODULO_H
#define PERSISTENCIADEMODULO_H

#include "Modulo.h"

#include <iostream>
#include <string>

using namespace std;

class PersistenciaDeModulo{
private:
    /* data */
public:
    PersistenciaDeModulo(string nomeDoArquivo);
    virtual ~PersistenciaDeModulo();
    void salvarEmAquivo(Modulo* mod);
    Modulo* lerArquivo();

};





#endif