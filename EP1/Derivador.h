#include "Sinal.h"
#include <iostream>
#include <string>

using namespace std;


class Derivador{
private:

    // Declarar como variaveis locais:
    int comprimentoIN;
    double* sequenciaIN;
    Sinal* sinalIN; 

    double* sequenciaOUT;

public:
    Derivador();
    virtual ~Derivador();
    Sinal* processar(Sinal* sinalIN);

};