#include "Sinal.h"
#include "Grafico.h"

#include <iostream>
#include <string>

using namespace std;

Sinal::Sinal(double* sequencia, int comprimento) : comprimento(comprimento){ // retirar o try-catch e colocar no menu.cpp
    try{
        if (comprimento <= 0){
            throw new invalid_argument("comprimento menor que 0");
        }
        // caso dê erro, devo fazer alguma coisa?

        this->sequencia = new double[comprimento];
        for (int i = 0; i < comprimento; i++){
            this->sequencia[i] = sequencia[i];
        }
    }
    catch(invalid_argument *e){
        cout << "ERRO - comprimento menor q 0" << endl; // Retirar o printf
        delete e;
    }
}

Sinal::Sinal(double constante, int comprimento) : comprimento(comprimento){ // retirar o try-catch e colocar no menu.cpp
    try{
        if (comprimento <= 0){
            throw new invalid_argument("Comprimento menor que 0");
        }   
        this->sequencia = new double[comprimento];
        for (int i = 0; i < comprimento; i++){
            this->sequencia[i] = constante;
        }
    }
    catch(invalid_argument *e){
        cout << "Erro - comprimento menor que 0" << endl; // Retirar o printf
        delete e;
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
