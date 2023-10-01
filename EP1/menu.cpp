#include <cmath>
#include "Sinal.h"
#include <iostream>
#include <string>

using namespace std;

// criar uma outra função void para aquisição de sinal 

void menu(){
    int resposta;
    cout << "    Simulink em C++" << endl;
    cout << "Qual simulacao voce gostaria de fazer?\n1) Piloto Automatico\n2)Sua propria sequencia de operacoes" << endl;

    cin >> resposta >> endl; // Verificar a sintaxe

    switch (resposta)
    {
    case 1:
        cout << "Escolha: 1" << endl;
        break;
    
    case 2:
        cout << "Escolha 2" << endl;

        break;

    default:
        break;
    }
    




}