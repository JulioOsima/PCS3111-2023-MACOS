#include "Circuito.h"

Circuito::Circuito(){
    ID = proximoID++;
}

Circuito::~Circuito(){
}

int Circuito::proximoID = 1;

int Circuito::getID(){
    return ID;
}

void Circuito::imprimir(){
    cout << "Circuito com ID " << this->getID() << endl;
}

int Circuito::getUltimoID(){ // pq o static da erro?
    if (proximoID - 1 <= 0){
        return 0;
    }
    
    return (proximoID - 1);
    
    // return o ultimo ID
    
}
