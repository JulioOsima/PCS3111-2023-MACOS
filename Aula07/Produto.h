#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>

using namespace std;

class Produto {
private:
    string nome;
    

public:
    double preco;
    Produto(string nome, double preco);
    virtual ~Produto();

    string getNome();
    virtual double getPreco();
    void imprimir();
};

#endif
