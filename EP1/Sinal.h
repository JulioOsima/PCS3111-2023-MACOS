#ifndef SINAL_H
#define SINAL_H


#include <iostream>
#include <string>

using namespace std;

class Sinal{
private:
    int comprimento;
    double *sequencia = new double[comprimento]; // DELETADO EM:
    double *sequenciaCopia = new double[comprimento]; // DELETADO EM:
    
    string nomeDoSinal;
    
public:
    Sinal(double *sequencia, int comprimento);
    virtual ~Sinal();
    double* getSequencia();
    int getComprimento();
    void imprimir(string nomeDoSinal);


};


#endif