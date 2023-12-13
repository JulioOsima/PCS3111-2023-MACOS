#include "LocacaoComercial.h"
#include <iostream>
#include <stdexcept>
#include <cmath>

using namespace std;

LocacaoComercial::LocacaoComercial(string endereco, double preco, int vencimento, int area):Locacao(endereco, preco, vencimento), area(area){}

LocacaoComercial::~LocacaoComercial() {}

int LocacaoComercial::getArea() {
    return area;
}

double LocacaoComercial::calcularTotal(int diasAntecipados){
    if (this->getArea() <= 50){
        return this->getPreco();
    }
    if (this->getArea() > 50){
        if (diasAntecipados >= 8){
            return this->getPreco() * 0.95;
        }
        if (diasAntecipados < 0){
            return this->getPreco() + (this->getPreco() * 0.02 * (-1) * diasAntecipados);
        }
        return this->getPreco();
    }
    return 0;
}

void LocacaoComercial::imprimir() {
    cout << "LocacaoComercial: " << getEndereco() << "," << getArea() << "m2, R$ " << getPreco() << " - Vencimento: " << getVencimento() << "\n";
}