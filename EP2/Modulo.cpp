#include "Modulo.h"

Modulo::Modulo():CircuitoSISO(){
    lista = new list<CircuitoSISO*>();
}

Modulo::~Modulo(){
    while (lista->empty() == false){
        CircuitoSISO *p = lista->front();
        lista->pop_front();
        delete p;
    }
    delete lista;
}

void Modulo::adicionar(CircuitoSISO* circ){
    lista->push_back(circ);
}

void Modulo::imprimir(){
    cout << "Modulo com ID " << this->getID() << " e:" << endl;
    list<CircuitoSISO*>::iterator i = lista->begin();
    while (i != lista->end()){
        cout << "Circuito com ID " << (*i)->getID() << endl;
    }
    cout << "--" << endl;
}

list<CircuitoSISO*>* Modulo::getCircuitos(){
    return lista;
}
