#include "Somador.h"

Somador::Somador() : CircuitoMISO(){

}

Somador::~Somador(){
delete[] sequenciaSomada;
}

Sinal* Somador::processar(Sinal* sinalIN1, Sinal* sinalIN2){
    // O q fazer se o metodo receber apenas um sinal??????
    
   int comprimentoSoma;

    if ((sinalIN1->getComprimento()) >= (sinalIN2->getComprimento())){
        comprimentoSoma = (sinalIN2->getComprimento()); 
    }
    if ((sinalIN2->getComprimento()) > (sinalIN1->getComprimento())){
        comprimentoSoma = (sinalIN1->getComprimento());
    }
    
    sequenciaSomada = new double[comprimentoSoma]; // DELETADO EM:

    for (int i = 0; i < comprimentoSoma; i++){
        sequenciaSomada[i] = sinalIN1->getSequencia()[i] + sinalIN2->getSequencia()[i];
    }
    Sinal *sinalSomado = new Sinal(sequenciaSomada, comprimentoSoma);
    return sinalSomado;
} 


    
    



