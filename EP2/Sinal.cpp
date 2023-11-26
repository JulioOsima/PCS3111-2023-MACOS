#include "Sinal.h"
#include "Grafico.h"

#include <iostream>
#include <string>

using namespace std;

Sinal::Sinal(double* sequencia, int comprimento) : comprimento(comprimento){ // retirar o try-catch e colocar no menu.cpp
    if (comprimento <= 0){
        throw new invalid_argument("comprimento menor que 0");
    }
    // caso dê erro, devo fazer alguma coisa?

    this->sequencia = new double[comprimento]; // Copia os valores do argumento sequencia para o atributo privado sequencia
    for (int i = 0; i < comprimento; i++){
        this->sequencia[i] = sequencia[i];
    }
}
Sinal::Sinal(double constante, int comprimento) : comprimento(comprimento){ // retirar o try-catch e colocar no menu.cpp
    if (comprimento <= 0){
        throw new invalid_argument("Comprimento menor que 0");
    }   
    this->sequencia = new double[comprimento];
    for (int i = 0; i < comprimento; i++){
        this->sequencia[i] = constante;
    }   
}

Sinal::~Sinal(){
    delete[] sequencia;
}

double* Sinal::getSequencia(){
    return sequencia;
}

int Sinal::getComprimento(){
    return comprimento;
}

void Sinal::imprimir(string nomeDoSinal){
    Grafico *graficoSinal = new Grafico(nomeDoSinal, sequencia, comprimento); 
    graficoSinal->plot();
    delete graficoSinal;   
}

void Sinal::imprimir(){
    // Teste
    for (int i = 0; i < comprimento; i++){
        cout << sequencia[i] << endl;
    }
    cout << "--" << endl;
}

void Sinal::imprimir(int tamanho){
    if (tamanho >= comprimento){
        for (int i = 0; i < comprimento; i++){
            cout << sequencia[i] << endl;
        }
        cout << "--" << endl;
    }
    else{
        for (int j = 0; j < tamanho; j++){
            cout << sequencia[j] << endl;
        }
        cout << "--" << endl;
    }
}
