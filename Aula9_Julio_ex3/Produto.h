#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>

using namespace std;

class Produto {
private:
    string nome;
    double preco;
    bool disponivel;

public:
    Produto(string nome, double preco);
    ~Produto(); 

    string getNome();
    double getPreco(); 

    bool getDisponivel();
    void setDisponivel(bool disponivel);

    void imprimir();
};

#endif
