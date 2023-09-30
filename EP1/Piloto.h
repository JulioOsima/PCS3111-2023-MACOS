#include "Sinal.h"
#include "Amplificador.h"
#include "Integrador.h"
#include <iostream>
#include <string>

using namespace std;

class Piloto{
private:
    double ganho;
    int comprimentoIN;
    double* sequenciaIN = new double[comprimentoIN]; // DELETADO EM:
    Sinal* sinalIN = new Sinal(sequenciaIN, comprimentoIN); // DELETADO EM:

    double* sequenciaOUT = new double[comprimentoIN]; // DELETADO EM:
    Sinal* sinalOUT = new Sinal(sequenciaOUT, comprimentoIN);
    

public:
    Piloto(double ganho);
    virtual ~Piloto();
    Sinal* processar(Sinal* sinalIN);

};