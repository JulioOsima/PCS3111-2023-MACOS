#ifndef CIRCUITO_H
#define CIRCUITO_H

#include <iostream>
#include <string>

using namespace std;

class Circuito{
private:
    


public:
    Circuito();
    virtual ~Circuito() = 0; // Verificar
    int getID();
    void imprimir(); 
    static int getUltimoID();
};

#endif