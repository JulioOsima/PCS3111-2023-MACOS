<<<<<<< HEAD
#ifndef COMBO_H
#define COMBO_H

// Faca os includes necessarios
#include <string>
#include "Produto.h"

using namespace std;

class Combo: public Produto {
private:
    //Inclua aqui os atributos necessarios

    Produto **p;
    int quantidadeDeProdutos;
    string nome;
    double desconto;

public:
    Combo(string nome, Produto **p, int quantidadeDeProdutos, double desconto);
    virtual ~Combo();
    Produto **getProdutos();
    int getQuantidadeDeProdutos();
    double getDesconto();
    void imprimir();

};
=======
#ifndef COMBO_H
#define COMBO_H

// Faca os includes necessarios
#include <string>
#include "Produto.h"

using namespace std;

class Combo: public Produto {
private:
    //Inclua aqui os atributos necessarios

    Produto **p;
    int quantidadeDeProdutos;
    string nome;
    double desconto;

public:
    Combo(string nome, Produto **p, int quantidadeDeProdutos, double desconto);
    virtual ~Combo();
    Produto **getProdutos();
    int getQuantidadeDeProdutos();
    double getDesconto();
    void imprimir();

};
>>>>>>> bdf4de33cd26a510d764ab76d420494f91803bc6
#endif