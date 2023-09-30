#include "Sinal.h"
#include <iostream>
#include <string>

using namespace std;

class Integrador{
private:
    int comprimentoIN;
    double* sequenciaIN = new double[comprimentoIN]; // DELETADO EM:
    Sinal* sinalIN = new Sinal(sequenciaIN, comprimentoIN); // DELETADO EM:

    double* sequenciaOUT = new double[comprimentoIN]; // DELETADO EM:
    Sinal* sinalOUT = new Sinal(sequenciaOUT, comprimentoIN); // DELETADO EM:


public:
    Integrador();
    virtual ~Integrador();
    Sinal* processar(Sinal* sinalIN);

};