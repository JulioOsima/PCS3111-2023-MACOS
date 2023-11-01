#include "Sinal.h"

#include <iostream>
#include <string>

using namespace std;

Sinal::Sinal(double* sequencia, int comprimento) : comprimento(comprimento){
    try{

        // Colocar um IF para dar throw no erro, se comprimento <= 0

        this->sequencia = new double[comprimento];
        for (int i = 0; i < comprimento; i++){
            this->sequencia[i] = sequencia[i];
        }
    }
    catch(invalid_argument *e){
        cout << "ERRO" << endl;
    }
}

Sinal::Sinal(double constante, int comprimento) : comprimento(comprimento){
    try{
        
        // Colocar um IF para dar throw no erro, se comprimento <= 0

        this->sequencia = new double[comprimento];
        for (int i = 0; i < comprimento; i++){
            this->sequencia[i] = constante;
        }

    }
    catch(invalid_argument *e){
        
    }
    
}
