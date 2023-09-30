#include "Sinal.h"
#include <iostream>
#include <string>

using namespace std;

class Amplificador{
private:
    double ganho;
    int comprimentoSA;
    double* sequenciaAmplificada = new double[comprimentoSA]; //DELETADO EM:
    Sinal* sinalIN = new Sinal(sequenciaAmplificada, comprimentoSA); // DELETADO EM:

public:
    
    Amplificador(double ganho);
    virtual ~Amplificador();
    Sinal* processar(Sinal* sinalIN);
    void setGanho(double ganho);
    double getGanho();


};