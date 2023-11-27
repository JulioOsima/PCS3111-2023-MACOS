#ifndef CIRCUITO_H
#define CIRCUITO_H

#include <iostream>

using namespace std;

class Circuito{
private:
    
int ID;
static int proximoID;

public:
    Circuito();
    virtual ~Circuito() = 0; // Verificar
    int getID();
    void imprimir(); 
    static int getUltimoID();
};

#endif