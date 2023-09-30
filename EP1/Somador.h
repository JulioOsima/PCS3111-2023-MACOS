#include "Sinal.h"
#include <iostream>
#include <string>


using namespace std;

class Somador{
private:
    int comprimentoIN1, comprimentoIN2;
    double* sequenciaIN1 = new double[comprimentoIN1]; // DELETADO EM:
    double* sequenciaIN2 = new double[comprimentoIN2]; // DELETADO EM:
    
    
    Sinal *sinalIN1 = new Sinal(sequenciaIN1, comprimentoIN1); // DELETADO EM:
    Sinal *sinalIN2 = new Sinal(sequenciaIN2, comprimentoIN2); // DELETADO EM:

public:
    Somador();
    virtual ~Somador();
    Sinal* processar(Sinal* sinalIN1, Sinal* sinalIN2);

};




