#ifndef LOCACAO_RESIDENCIAL_H
#define LOCACAO_RESIDENCIAL_H

#include "Locacao.h"
#include <string>

using namespace std;

class LocacaoResidencial:public Locacao {
private:
    int quartos;

public:
    LocacaoResidencial(string endereco, double preco, int vencimento, int quartos);
    virtual ~LocacaoResidencial();
    int getQuartos();
    double calcularTotal(int diasAntecipados);
    void imprimir();
};

#endif // LOCACAO_RESIDENCIAL_H