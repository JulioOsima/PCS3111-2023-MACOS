#include "LocacaoRegiao.h"
#include <iostream>
#include <stdexcept>

using namespace std;

LocacaoRegiao::LocacaoRegiao(string regiao) {
    this->regiao = regiao;
}

LocacaoRegiao::~LocacaoRegiao() {
    while (vectorDeLocacoes->empty() == false){
        Locacao* l = vectorDeLocacoes->back();
        vectorDeLocacoes->pop_back();
        delete l;
    }
    delete vectorDeLocacoes;
}

string LocacaoRegiao::getRegiao() {
    return regiao;
}

void LocacaoRegiao::adicionarLocacao(Locacao* locacao) {
    vectorDeLocacoes->push_back(locacao);
}

vector<Locacao*>* LocacaoRegiao::getLocacoes() {
    return vectorDeLocacoes;
}

double LocacaoRegiao::calcularTotal(int diasAntecipados) {
    double custoTotal = 0;
    if (vectorDeLocacoes->empty() == true){
        throw new logic_error("Deve haver ao menos 1 locacao");
    }
    
    for (int i = 0; i < vectorDeLocacoes->size(); i++){
        try{
             custoTotal += vectorDeLocacoes->at(i)->calcularTotal(diasAntecipados);
        }
        catch(invalid_argument *e){
            custoTotal += vectorDeLocacoes->at(i)->getPreco();
        }
    }
    return custoTotal;
}

void LocacaoRegiao::imprimir() {
    cout << "LocacaoRegiao:" << getRegiao() << "\n";
    for (int i = 0; i < vectorDeLocacoes->size(); i++){
        vectorDeLocacoes->at(i)->imprimir();
    }
    // COMPLETE
}
