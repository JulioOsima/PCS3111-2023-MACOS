#ifndef COMBO_H
#define COMBO_H
#include "Produto.h"

#include <string>
#include <vector>

using namespace std;

//Modifique a classe Combo para que seus produtos estejam em um container vector

class Combo : public Produto {
private:
    int quantidadeMaxima;
    int quantidade;
    Produto **produtos;
    vector <Produto*>* combo;
public:
    Combo(string nome);
    virtual ~Combo();
    void adicionar(Produto *p);
    double getPreco();
    vector <Produto*>* getProdutos();
    void imprimir();


    /*Combo(string nome, int quantidadeMaxima);
    virtual ~Combo();

    void adicionar(Produto* p);
    double getPreco();
    Produto **getProdutos();
    int getQuantidade();

    void imprimir(); */
};

#endif