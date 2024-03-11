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
#include <vector>

using namespace std;

class PersistenciaDeModulo{
private:
    string nomeDoArquivo;
    vector<Modulo*>* vectorDeModulos;       // deletado em: PersistenciaDeModulo.cpp l14
    vector<string>* vectorDeStrings;        // deletado em: PersistenciaDeModulo.cpp l13
    void interior(Modulo* moduloPrincipal, int i);
    void adicionaCircuitos(Modulo* modulo, int a, int b);
    int k;
    void procuraModuloInterno(string moduloAtual, int a, int b);
    string verificaModulo(CircuitoSISO* circuito);
public:
    PersistenciaDeModulo(string nomeDoArquivo);
    virtual ~PersistenciaDeModulo();
    void salvarEmArquivo(Modulo* mod);
    Modulo* lerDeArquivo();
};

#endif