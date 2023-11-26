#include "ModuloEmSerie.h"
#include <iostream>
#include <stdexcept>

using namespace std;

ModuloEmSerie::ModuloEmSerie():Modulo(){

}

ModuloEmSerie::~ModuloEmSerie(){

}

Sinal* ModuloEmSerie::processar(Sinal* SinalIN){ 
    list<CircuitoSISO*>::iterator i = getCircuitos()->begin();
    bool listaVazia;
    // Criar um sinal intermediario 
    

        // Copiar a entrada para o sinal intermediario e deletar a entrada

    // Criar um sinal de saida

   while (i != getCircuitos()->end()){
        if ((*i) != nullptr){
            listaVazia = false;
        }   
        i++;
   }
   list<CircuitoSISO*>::iterator j = getCircuitos()->begin();
   if (listaVazia == false){
        while (j != getCircuitos()->end()){
            SinalIN = (*j)->processar(SinalIN);
        }
        return SinalIN;
   }
   throw new logic_error("Não possui ciruitos SISO");
   return 0; // esse return precisa estar aqui?
}
   
