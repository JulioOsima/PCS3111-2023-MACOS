#include "Sinal.h"
#include <iostream>
#include <string>

using namespace std;

class Integrador{
private:
    double* sequenciaOUT;

public:
    Integrador();
    virtual ~Integrador();
    Sinal* processar(Sinal* sinalIN);
};