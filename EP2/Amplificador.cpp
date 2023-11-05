#include "Amplificador.h"

Amplificador::Amplificador(double ganho):ganho(ganho){
// ...
}

Amplificador::~Amplificador(){
// ...
}

double Amplificador::getGanho(){
    return ganho;
}

void Amplificador::setGanho(double ganho){
    this->ganho = ganho;
}
