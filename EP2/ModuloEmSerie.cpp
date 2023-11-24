#include "ModuloEmSerie.h"

ModuloEmSerie::ModuloEmSerie():Modulo(){

}

ModuloEmSerie::~ModuloEmSerie(){

}

Sinal* ModuloEmSerie::processar(Sinal* SinalIN){ // retirar o try-catch e colocar no menu.cpp
    double* sequenciaIntermediaria = new double[SinalIN->getComprimento()];
    Sinal* sinalIntermediario = new Sinal(sequenciaIntermediaria, SinalIN->getComprimento());

    sinalIntermediario = SinalIN;
    try{
        if (getCircuitos() == NULL){
            throw new logic_error("Lista vazia");
        }
        else
        for (it = getCircuitos()->begin(); it != getCircuitos()->end(); it++){
            //sinalIntermediario = getCircuitos()->sinalIntermediario; a ideia é colocar SinalIN na func listada 
        }
        
    }
    catch(logic_error *e){
        delete e;
    }
    
}