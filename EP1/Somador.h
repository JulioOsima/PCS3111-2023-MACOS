#include "Sinal.h"
#include <iostream>
#include <string>


using namespace std;

class Somador{
private:

    // Definir essas variaveis como variaveis locais:
    double* sequenciaIN1;
    double* sequenciaIN2;

public:
    Somador();
    virtual ~Somador();
    Sinal* processar(Sinal* sinalIN1, Sinal* sinalIN2);
};




