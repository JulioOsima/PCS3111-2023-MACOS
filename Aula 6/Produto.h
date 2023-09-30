#ifndef PROD_H
#define PROD_H
#include <iostream>
#include <string>
using namespace std;

class Produto {
private:
    string nome;
    

public:
    double preco;
    Produto(string nome, double preco);
    virtual ~Produto();

    double getPreco();
    string getNome();

    void imprimir();
};

#endif