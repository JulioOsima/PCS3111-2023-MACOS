#ifndef CIRCUITO_H
#define CIRCUITO_H

#include <iostream>

using namespace std;

class Circuito{
private:
    
public:
    int ID;
    static int proximoID;
    Circuito();
    virtual ~Circuito() = 0; // Verificar
    int getID();
    void imprimir(); 
    static int getUltimoID();
};

#endif