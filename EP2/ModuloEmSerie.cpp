#include "ModuloEmSerie.h"

ModuloEmSerie::ModuloEmSerie():Modulo(){
}

ModuloEmSerie::~ModuloEmSerie(){
    while (this->getCircuitos()->empty() == false){
         CircuitoSISO *p = this->getCircuitos()->front();
        this->getCircuitos()->pop_front();
        delete p;
    }
    delete this->getCircuitos();
}

Sinal* ModuloEmSerie::processar(Sinal* sinalIN){ 
    list<CircuitoSISO*>::iterator i = this->getCircuitos()->begin();
    bool listaVazia = true;
    while (i != this->getCircuitos()->end()){
        if ((*i) != nullptr){
            listaVazia = false;
        }   
        i++;
    }
    if (listaVazia == true){
        throw new logic_error("Não possui ciruitos SISO");
        return 0;
    }
    i = this->getCircuitos()->begin();
    while (i!= this->getCircuitos()->end()){
        sinalIN = (*i)->processar(sinalIN);
        sinalIN->imprimir();
        i++;
    }
    return sinalIN;// usei o msm sinal
}
   
