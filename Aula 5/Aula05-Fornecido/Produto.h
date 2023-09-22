#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>

using namespace std;

class Produto {
private:
    string nome;
    double preco;

public:
    Produto(string nome, double preco);

    string getNome();
    double getPreco();

    void imprimir();
};

#endif  // PRODUTO_H
