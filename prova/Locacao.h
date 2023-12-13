#ifndef LOCACAO_H
#define LOCACAO_H

#include <string>

using namespace std;

class Locacao  {
private:
    string endereco;
    double preco;
    int vencimento;
    //int diasAntecipados;

public:
    Locacao(string endereco, double preco, int vencimento);
    virtual ~Locacao();
    string getEndereco();
    double getPreco();
    void setPreco(double novo);
    int getVencimento();
    virtual double calcularTotal(int diasAntecipados) = 0;
    virtual void imprimir() = 0;
};
#endif // LOCACAO_H