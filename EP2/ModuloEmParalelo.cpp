#include "ModuloEmParalelo.h"
#include "Somador.h"

ModuloEmParalelo::ModuloEmParalelo(){ //definir hereditariedade

}

ModuloEmParalelo::~ModuloEmParalelo(){
    
}

Sinal* ModuloEmParalelo::processar(Sinal* sinalIN){
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
   
    double *sequenciaDeSaida = new double[60];
    Sinal* sinalDeSaida = new Sinal(sequenciaDeSaida, 60);
    i = getCircuitos()->begin();
    listaDeParalelos = new list<Sinal*>();
    list<Sinal*>::iterator k = listaDeParalelos->begin();

    Somador* sum = new Somador();
    while (i != getCircuitos()->end()){
        listaDeParalelos->push_back((*i)->processar(sinalIN));
    }
    for (k = listaDeParalelos->begin(); k != listaDeParalelos->end(); k++){
        sinalDeSaida = sum->processar((*k),(*(k++))); // Funciona?
    }

    delete[] sequenciaDeSaida;
    delete listaDeParalelos;

    return sinalDeSaida;
}
   