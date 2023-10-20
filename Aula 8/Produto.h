#ifndef PROD_H
#define PROD_H

#include <string>
using namespace std;

class Produto {
private:
   

public:

    string nome;
    double preco;

    Produto(string nome, double preco);
    virtual ~Produto();
    
    double getPreco();
    string getNome();
    
    virtual void imprimir() = 0;// Metodo é abstrato =>
};
#endif