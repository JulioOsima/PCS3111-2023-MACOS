#include "Piloto.h"
#include <iostream>
#include <string>

using namespace std;

Piloto::Piloto(double ganho):
ganho(ganho){
    amplificador = new Amplificador(ganho); // DELETADO EM: PILOTO.CPP-L15
    integrador = new Integrador(); // DELETADO EM: PILOTO.CPP-L16
}

Piloto::~Piloto(){
    delete amplificador;
    delete integrador;
}

Sinal* Piloto::processar(Sinal* sinalIN){
    sinalOUT = amplificador->processar(sinalIN);
    sinalOUT = integrador->processar(sinalOUT);

    return sinalOUT;
}