#include <cmath>
#include "Somador.h"
#include "Derivador.h"
#include "Piloto.h"
#include "ModuloRealimentado.h"
#include "Grafico.h"
#include <iostream>
#include <string>

using namespace std;

// Perguntas:
// 1) Onde entra o ModuloRealimentado?
// 2) Preciso declarar as funções daqui no arquivo main.cpp?
// 3) Preciso usar o ifndef em todos os aqruivos?
// 4) Da onde vem o erro de compilação do judge
// 5) Como deleto manualmente os itens criados nos outros aqruivos?
// 6) De onde vem os erros em relação ao grafico.h/grafico.cpp que aparecem quando compilo


Sinal* criarSinal(int tipo){
    int valor;
    double *sequencia1 = new double[60];

    int constante;
    double *sequencia2 = new double[60];

    int inclinacao;
    double *sequencia3 = new double[60];

    switch (tipo)
    {
    case 1:
        for (int i = 0; i < 60; i++)
        {
            sequencia1[i] = (5 + 3 * cos((i * M_PI)) / 8);
        }
        return new Sinal(sequencia1, 60);
    case 2:
        cout << "Qual o valor dessa constante?" << endl;
        cin >> constante;
        cout << "C = " << constante << endl;
        for (int i = 0; i < 60; i++)
        {
            sequencia2[i] = constante;
        }
        return new Sinal(sequencia2, 60);
    
    case 3:
        cout << "Qual a inclinacao dessa rampa?" << endl;
        cin >> inclinacao;
        cout << "a = " << inclinacao << endl;
        for (int i = 0; i < 60; i++)
        {
            sequencia3[i] = i * inclinacao;
        }
        return new Sinal(sequencia3, 60);
    default:
        cout << "Erro" << endl;
        return 0;
    }
}

Sinal* aquisicao(){
    int respostaAquisicao;
    cout << "Qual sinal voce gostaria de utilizar como entrada da sua simulacao? " << endl <<
            "1) 5+3*cos(n*pi/8)" << endl <<
            "2) constante" << endl << 
            "3) rampa" << endl;
    cin >> respostaAquisicao;
    cout << "Escolha: " << respostaAquisicao << endl;
    switch (respostaAquisicao)
    {
    case 1:

        // O q colocar aqui?

        // Criar o sinal com o modelo dado

        return criarSinal(respostaAquisicao);
    case 2:
        return criarSinal(respostaAquisicao);
    case 3:
        return criarSinal(respostaAquisicao);
    default:
        cout << "Erro!" << endl;
        break;
    }
}

void criaPlotaGrafico(string nome, double *sequencia, int comprimento){
    Grafico* grafico = new Grafico(nome, sequencia, comprimento); // DELETADO EM: menu.cpp-L88
    grafico->plot();
    delete grafico;
}

Piloto* piloto(double ganhop){
    Piloto *pilotoAutomatico = new Piloto(ganhop); // DELETADO EM:
    return pilotoAutomatico;
}

void menu(){
    int resposta;
    cout << "    Simulink em C++" << endl;
    cout << "Qual simulacao voce gostaria de fazer?"<< endl << 
            "1) Piloto Automatico" << endl << 
            "2)Sua propria sequencia de operacoes" << endl;
    cin >> resposta;

    // switch(resposta) caso 1
    double g1 = 0;
    Sinal* s1;
    
    // switch(resposta) caso 1

    // switch(resposta) caso 2
    int operacao; 
    int continuar = 1;
    // switch(resposta) caso 2

    // switch(resposta) caso2 / switch(opercao) caso 1
    double g2 = 0;
    Sinal* s2;
    Amplificador *amplificador = new Amplificador(g2); // DELETADO EM: menu.cpp-L137
    // switch(resposta) caso2 / switch(opercao) caso 1

    // switch(resposta) caso2 / switch(opercao) caso 2
    Sinal *s3;
    Somador *somador = new Somador(); // DELETADO EM: menu.cpp-L146
    // switch(resposta) caso2 / switch(opercao) caso 2

    // switch(resposta) caso2 / switch(opercao) caso 3
    Derivador *derivador = new Derivador(); // DELETADO EM: menu.cpp-L152
    // switch(resposta) caso2 / switch(opercao) caso 3

    // switch(resposta) caso2 / switch(opercao) caso 4
    Integrador *integrador = new Integrador(); // DELETADO EM: menu.cpp-L158
    // switch(resposta) caso2 / switch(opercao) caso 4  



    switch (resposta)
    {
    case 1:
        
        cout << "Escolha: 1" << endl;
        s1 = aquisicao(); // Preciso criar uma variavel do tipo sinal aqui?
        cout << "Qual o ganho do acelerador?" << endl;
        cin >> g1;
        cout << "g = " << g1 << endl;

        
        piloto(g1)->processar(s1); //

        criaPlotaGrafico("Velocidade do carro",(s1->getSequencia()), (s1->getComprimento()));

        break;
    
    case 2:
        
        cout << "Escolha: 2" << endl;
        s2 = aquisicao();
        while (continuar == 1)      
        {
            cout << "Qual operacao voce gostaria de fazer?" << endl << 
                    "1) Amplificar" << endl << 
                    "2) Somar" << endl << 
                    "3) Derivar" << endl <<
                    "4) Integrar" << endl;
            cin >> operacao;
            cout << "Escolha: " << operacao << endl;    
            switch (operacao)
            {
            case 1:
                cout << "Qual o ganho dessa amplificacao?" << endl;
                cin >> g2;
                cout << "g = " << g2 << endl;
                amplificador->setGanho(g2);
                amplificador->processar(s2);

                delete amplificador;
                break;
            case 2:
                cout << "Informe mais um sinal para ser somado." << endl;
                s3 = aquisicao();
                somador->processar(s2, s3);

                delete somador;
                break;
            case 3:
                derivador->processar(s2);
                
                delete derivador;
                break;
            case 4:
                integrador->processar(s2);
                
                delete integrador;
                break;
            default:
                cout << "Erro" << endl;
                break;
            }
            cout << "O que voce quer fazer agora?" << endl <<
                    "1) Realizar mais uma operacao no resultado" << endl << 
                    "2) Imprimir o resultado para terminar" << endl;
            cin >> continuar;
            cout << "Escolha: " << continuar << endl;
            if (continuar != 1 && continuar != 2)
            {
                cout << "Valor inválido" << endl;
            }
            
        }

        criaPlotaGrafico("Resultado Final", (s2->getSequencia()), (s2->getComprimento()));

        break;

    default:
        cout << "Erro!" << endl;
        break;
    }
    
}