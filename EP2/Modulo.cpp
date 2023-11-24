#include "Modulo.h"

Modulo::Modulo():CircuitoSISO(){
    list<CircuitoSISO*>::iterator it;
    

}

Modulo::~Modulo(){
    
}

void Modulo::adicionar(CircuitoSISO* circ){

// Adicionar o metodo

    lista->push_back(circ);

}

void Modulo::imprimir(){//Erro na definiçao de hereditariedade (avô)

    cout << "Modulo com ID " << this->getID() << " e:" << endl;
    for (int i = 0; i < lista->size(); i++){
        cout << "Circuito com ID "<< "/  como colocar o id desde o primeiro?   /" << endl;
    }
}

list<CircuitoSISO*>* Modulo::getCircuitos(){
    return lista;
}
