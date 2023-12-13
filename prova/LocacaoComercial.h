#ifndef LOCACAO_COMERCIAL_H
#define LOCACAO_COMERCIAL_H

#include <string>
#include "Locacao.h"

using namespace std;

class LocacaoComercial:public Locacao {
private:
    int area;
public:
    LocacaoComercial(string endereco, double preco, int vencimento, int area);
    virtual ~LocacaoComercial();
    int getArea();
    double calcularTotal(int diasAntecipados);
    void imprimir();

};

#endif // LOCACAO_COMERCIAL_H