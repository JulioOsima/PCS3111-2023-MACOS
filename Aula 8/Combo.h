#ifndef COMBO_H
#define COMBO_H

// Faca os includes necessarios
#include "ProdutoNormal.h"


class Combo : public Produto{
private:
    string nomeCombo;
    int quantidadeMaxima;
    ProdutoNormal** vetorDeProdutosNormais;
    int quantidadeAtual;
public:
    Combo(string nome, int quantidadeMaxima);
    virtual ~Combo();

    bool adicionar(ProdutoNormal *ep);
    ProdutoNormal **getProdutosNormais();
    int getQuantidadeDeProdutosNormais();

    void imprimir();
};
#endif