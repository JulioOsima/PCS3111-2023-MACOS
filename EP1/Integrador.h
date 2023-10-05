#include "Sinal.h"
#include <iostream>
#include <string>

using namespace std;

class Integrador{
private:
    // Declarar como variaveis locais:
    double* sequenciaOUT;

public:
    Integrador();
    virtual ~Integrador();
    Sinal* processar(Sinal* sinalIN);

};