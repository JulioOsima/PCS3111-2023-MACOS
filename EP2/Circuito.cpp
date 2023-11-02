#include "Circuito.h"

#include <iostream>
#include <string>

using namespace std;

Circuito::Circuito(){

}

Circuito::~Circuito(){

 // Como declarar o destrutor abstrato?
}

int Circuito::getID(){
    return ID;
}

void Circuito::imprimir(){
    cout << "Circuito com ID " << this->getID() << endl;
}

int Circuito::getUltimoID(){ // pq o static da erro?
    if (/* verificar se nenhum circuito foi criado */){
        /* code */
    }
    
    // return o ultimo ID
    
}
