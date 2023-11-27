#include "ModuloEmSerie.h"

ModuloEmSerie::ModuloEmSerie():Modulo(){
}

ModuloEmSerie::~ModuloEmSerie(){
}

Sinal* ModuloEmSerie::processar(Sinal* SinalIN){ 
    list<CircuitoSISO*>::iterator i = getCircuitos()->begin();
    bool listaVazia = true;
    while (i != getCircuitos()->end()){
        if ((*i) != nullptr){
            listaVazia = false;
        }   
        i++;
    }
    if (listaVazia == true){
        throw new logic_error("Não possui ciruitos SISO");
        return 0;
    }
    i = getCircuitos()->begin();
    while (i != getCircuitos()->end()){
        SinalIN = (*i)->processar(SinalIN);
    }
    return SinalIN;
}
   
