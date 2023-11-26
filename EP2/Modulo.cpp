#include "Modulo.h"

Modulo::Modulo():CircuitoSISO(){
    lista = new list<CircuitoSISO*>();
}

Modulo::~Modulo(){
    delete lista;
    // destruir o conteudo da lista
}

void Modulo::adicionar(CircuitoSISO* circ){
// Adicionar o metodo
    lista->push_back(circ);
}

void Modulo::imprimir(){//Erro na definiçao de hereditariedade (avô)

    cout << "Modulo com ID " << this->getID() << " e:" << endl;
    list<CircuitoSISO*>::iterator i = lista->begin();
    while (i != lista->end()){
        cout << "Circuito com ID " << (*i)->getID() << endl;
    }
}

list<CircuitoSISO*>* Modulo::getCircuitos(){
    return lista;
}
