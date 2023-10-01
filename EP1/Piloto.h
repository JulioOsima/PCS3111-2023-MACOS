#include "Sinal.h"
#include "Amplificador.h"
#include "Integrador.h"
#include <iostream>
#include <string>

using namespace std;

//Posso utilizar o Herança aqui? Isso mudaria os métodos publicos do padrao

// Posso utilizar o princípio de "friend class" para usar um método privado de uma classe como método privado em outra classe?


class Piloto{  
private:
    double ganho;
    int comprimentoIN;
    double* sequenciaIN = new double[comprimentoIN]; // DELETADO EM:
    Sinal* sinalIN = new Sinal(sequenciaIN, comprimentoIN); // DELETADO EM:

    Amplificador *amplificador;
    Integrador *integrador;

    double* sequenciaOUT = new double[comprimentoIN]; // DELETADO EM:
    Sinal* sinalOUT = new Sinal(sequenciaOUT, comprimentoIN); // DELETADO EM: 
    

public:
    Piloto(double ganho);
    virtual ~Piloto();
    Sinal* processar(Sinal* sinalIN);

};