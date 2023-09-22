#include "Produto.h"
#include <iostream>
#include <string>
#define MAXIMO_DE_PRODUTOS 10

class Pedido {
    private:
        int quantidade;
        Produto *produtos[MAXIMO_DE_PRODUTOS];

    public:
        bool adicionar(Produto* produto);

        double getPrecoTotal();

        void imprimir();
};