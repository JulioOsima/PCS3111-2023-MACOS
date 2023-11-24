#include "Circuito.h"

#include <iostream>
#include <string>

using namespace std;

Circuito::Circuito(){
    ID = proximoID++;
}

Circuito::~Circuito(){

 // Como declarar o destrutor abstrato?
}

int Circuito::proximoID = 1;

int Circuito::getID(){
    return ID;
}

void Circuito::imprimir(){
    cout << "Circuito com ID " << this->getID() << endl;
}

int Circuito::getUltimoID(){ // pq o static da erro?
    return (proximoID - 1);
    
    // return o ultimo ID
    
}
