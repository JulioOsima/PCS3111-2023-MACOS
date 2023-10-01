#include "Sinal.h"
#include <iostream>
#include <string>

using namespace std;

class ModuloRealimentado{
private:
    double ganho;
    int comprimentoIN;
    double* sequenciaIN = new double[comprimentoIN];

    Sinal* sinalIN = new Sinal(sequenciaIN, comprimentoIN);

public:
    ModuloRealimentado(double ganho);
    virtual ~ModuloRealimentado();
    Sinal* processar(Sinal* sinalIN);
};