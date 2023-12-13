#ifndef LOCACAO_REGIAO_H
#define LOCACAO_REGIAO_H

#include "Locacao.h"
#include <string>
#include <vector>

using namespace std;

class LocacaoRegiao {
private:
    string regiao;
    Locacao* locacao;
    vector<Locacao*>* vectorDeLocacoes = new vector<Locacao*>();
public:
    LocacaoRegiao(string regiao);
    virtual ~LocacaoRegiao();
    string getRegiao();
    void adicionarLocacao(Locacao* locacao);
    vector<Locacao*>* getLocacoes();
    double calcularTotal(int diasAntecipados);
    void imprimir();
};

#endif // LOCACAO_REGIAO_H