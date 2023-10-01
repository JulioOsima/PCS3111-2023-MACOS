#include <cmath>
#include "Sinal.h"
// quais includes estao faltando?
#include <iostream>
#include <string>

using namespace std;

// OBS: Como funciona esse menu de selecao?
// Posso usar switch case?
// Posso usar \n como quebra de linha? Já que C é nucleo de C++

void aquisicao(){
    int respostaAquisicao;
    cout << "Qual sinal voce gostaria de utilizar como entrada da sua simulacao?\n1) 5+3*cos(n*pi/8)\n2) constante\n3) rampa" << endl;
    cin >> respostaAquisicao;
    cout << "Escolha: " << respostaAquisicao << endl;
    switch (respostaAquisicao)
    {
    case 2:
        cout << "Qual o valor dessa constante?" << endl;
        cin >> respostaAquisicao;
        cout << "C = " << respostaAquisicao << endl;
        break;
    case 3:
        cout << "Qual a inclinacao dessa rampa?" << endl;
        cin >> respostaAquisicao;
        cout << "a = " << respostaAquisicao << endl;

        break;
    default:
        cout << "Erro!" << endl;
        break;
    }
}

void menu(){
    int resposta;
    cout << "    Simulink em C++" << endl;
    cout << "Qual simulacao voce gostaria de fazer?\n1) Piloto Automatico\n2)Sua propria sequencia de operacoes" << endl;

    cin >> resposta; // Verificar a sintaxe

    switch (resposta)
    {
    case 1:
        cout << "Escolha: 1" << endl;
        aquisicao();

        break;
    
    case 2:
        cout << "Escolha 2" << endl;
        aquisicao();

        break;

    default:
        break;
    }
    
}