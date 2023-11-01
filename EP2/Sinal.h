#ifndef SINAL_H
#define SINAL_H

#include <iostream>
#include <string>

using namespace std;

class Sinal{
private:
    int comprimento;
    double* sequencia;
    
public:
    Sinal(double *sequencia, int comprimento);
    Sinal(double constante, int comprimento);
    ~Sinal();
    double* getSequencia();
    int getComprimento();
    void imprimir(string nomeDoSinal);
    void imprimir(); // usar para testar
    void imprimir(int tamanho);
};

#endif
