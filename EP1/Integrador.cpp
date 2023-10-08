#include "Integrador.h"
#include <iostream>
#include <string>


using namespace std;


Integrador::Integrador(){
// ...
}

Integrador::~Integrador(){
// ...
}

Sinal* Integrador::processar(Sinal* sinalIN){

    sequenciaOUT = new double[sinalIN->getComprimento()]; // DELETADO EM:

    sequenciaOUT[0] = (sinalIN->getSequencia()[0]);

    for (int i = 1; i < (sinalIN->getComprimento()); i++)
    {
        sequenciaOUT[i] = sequenciaOUT[i - 1] + (sinalIN->getSequencia()[i]);
        cout << "sequenciaOUT[" << i << "] = " << sequenciaOUT[i] << endl;
    }
    
    return new Sinal(sequenciaOUT, (sinalIN->getComprimento())); // DELETADO EM:
}