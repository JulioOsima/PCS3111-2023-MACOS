#include "Integrador.h"
#include "Amplificador.h"
#include <iostream>
#include <string>

using namespace std;

class Piloto{  
private:
    double ganho;

    Integrador *integrador;
    Amplificador *amplificador;
    
    double* sequenciaOUT;
    Sinal* sinalOUT;

public:
    Piloto(double ganho);
    virtual ~Piloto();
    Sinal* processar(Sinal* sinalIN);

};