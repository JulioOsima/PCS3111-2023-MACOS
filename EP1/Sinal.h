#ifndef SINAL_H
#define SINAL_H

#include <iostream>
#include <string>

using namespace std;

class Sinal{
private:
    int comprimento;
    double *sequencia; // Dessa forma o vetor tem "Comprimento" casas e vai de 0 à comprimento - 1 // DELETADO EM:
     // DELETADO EM:
    
    string nomeDoSinal;
    
public:
    Sinal(double *sequencia, int comprimento);
    virtual ~Sinal();
    double* getSequencia();
    int getComprimento();
    void imprimir(string nomeDoSinal);
};

#endif