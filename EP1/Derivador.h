#include "Sinal.h"
#include <iostream>
#include <string>

using namespace std;


class Derivador{
private:
    int comprimentoIN;
    double* sequenciaIN = new double[comprimentoIN]; // DELETADO EM:
    Sinal* sinalIN = new Sinal(sequenciaIN, comprimentoIN); // DELETADO EM:

    double* sequenciaOUT = new double[comprimentoIN]; // DELETADO EM:
    Sinal* sinalOUT = new Sinal(sequenciaOUT, comprimentoIN); // DELETADO EM:

public:
    Derivador();
    virtual ~Derivador();
    Sinal* processar(Sinal* sinalIN);

};