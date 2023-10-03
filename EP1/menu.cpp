#include <cmath>
#include "Sinal.h"
#include "Amplificador.h"
#include "Somador.h"
#include "Derivador.h"
#include "Integrador.h"
#include "Piloto.h"
#include "ModuloRealimentado.h"
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
    case 1:
        // O q colocar aqui?

        // Criar o sinal com o modelo dado

        break;
    case 2:
        cout << "Qual o valor dessa constante?" << endl;
        cin >> respostaAquisicao;
        cout << "C = " << respostaAquisicao << endl;
        //Sinal *sinalConstante = new Sinal( ,60);  Criar uma nova sequencia? E depois criar um for para que todas as casas do vetor tenham o msm numero?

        // Criar o sinal com o valor constante. O comprimento ssempre tem tamanho igual a 60

        break;
    case 3:
        cout << "Qual a inclinacao dessa rampa?" << endl;
        cin >> respostaAquisicao;
        cout << "a = " << respostaAquisicao << endl;

        // Criar o sinal baseado na função afim de coeficiente "a" e constante igual a 0
 
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
    cin >> resposta; // Preciso colocar um "\n" ou um "endl" aqui?

    switch (resposta)
    {
    case 1:
        double g;
        cout << "Escolha: 1" << endl;
        aquisicao();
        cout << "Qual o ganho do acelerador?" << endl;
        cin >> g;
        cout << "g = " << g << endl;

        Piloto *pilotoAutomatico = new Piloto(g); // DELETADO EM:
        // pilotoAutomatico->processar(); Adicionar o sinal criado 

        // Adicionar as funções 
        // Imprimir o sinal de saída com o título : "Velocidade do carro"
        break;
    
    case 2:
        int resposta2; 
        int continuar = 1;
        cout << "Escolha: 2" << endl;
        aquisicao();
        while (continuar == 1)      
        {
            cout << "Qual operacao voce gostaria de fazer?\n1) Amplificar\n2) Somar\n3) Derivar\n4) Integrar" << endl;
            cin >> resposta2;
            cout << "Escolha: " << resposta2 << endl;    
            switch (resposta2)
            {
            case 1:
                double g;
                cout << "Qual o ganho dessa amplificacao?" << endl;
                cin >> g;
                cout << "g = " << g << endl;
                // Chamar a função de amplificação
                break;
            case 2:
                cout << "Informe mais um sinal para ser somado." << endl;
                //  aquisicao();
                // Chamar a função de Soma com o resultado de aquisição -> soma(sinal1, aquisicao());
                break;
            case 3:
                // // Chamar a função de Derivar
                break;
            case 4:
                // Chamar a função de Integrar
                break;
            default:
                break;
            }
            cout << "O que voce quer fazer agora?\n1) Realizar mais uma operacao no resultado\n2) Imprimir o resultado para terminar" << endl;
            cin >> continuar;
            cout << "Escolha: " << continuar << endl;
            if (continuar != 1 && continuar != 2)
            {
                cout << "Valor inválido" << endl;
            }
            
        }
        // Imprimir o sinal de saida com titulo: "Resultado Final"
        break;

    default:
    cout << "Erro!" << endl;
        break;
    }
    
}