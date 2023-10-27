#ifndef PRODUTO_NORMAL_H
#define PRODUTO_NORMAL_H

#include"Produto.h"
#include <string>

using namespace std;

// Faça a classe ProdutoNormal ser uma filha concreta de Produto
class ProdutoNormal : public Produto {
public:
    ProdutoNormal(string nome, double preco);
    virtual ~ProdutoNormal();
    void imprimir();
};
#endif