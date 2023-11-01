#ifndef CIRCUITO_H
#define CIRCUITO_H

#include <iostream>
#include <string>

using namespace std;

class Circuito{
private:
    static int ID;


public:
    Circuito();
    virtual ~Circuito();
    int getID();
    void imprimir(); 
    static int getUltimoID();
};

#endif