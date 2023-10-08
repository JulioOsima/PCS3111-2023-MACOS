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
// 1) Onde entra o ModuloRealimentado? R: Entra no Piloto Automatico
// 2) Preciso declarar as funções daqui no arquivo main.cpp? R: Sim
// 3) Preciso usar o ifndef em todos os aqruivos? R: Sim 
// 4) Da onde vem o erro de compilação do judge R: Provavelmente pela falta de ifndef
// 5) Como deleto manualmente os itens criados nos outros aqruivos? 
// 6) De onde vem os erros em relação ao grafico.h/grafico.cpp que aparecem quando compilo  

// ao compilar utilizar um identificador de compilacao = g++ -std=c++11 *.cpp -o ep1


// Coisas para mudar:
// Deletar os itens do heap
// Adicionar o modulo realimentado


//EXEPLO 1:
// 1 - 2 - 5 - 0.2 -> resposta (quase um log)


Sinal* criarSinal(int tipo){
    int valor;
    double *sequencia1 = new double[60];

    int constante;
    double *sequencia2 = new double[60];

    double inclinacao;
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
        cout << "Qual o valor dessa constante?" << endl << 
                "C = ";
        cin >> constante;
        cout << "" << endl;
        for (int i = 0; i < 60; i++) // Alterei para 59
        {
            sequencia2[i] = constante;
        }
        return new Sinal(sequencia2, 60);
    
    case 3:
        cout << "Qual a inclinacao dessa rampa?" << endl << 
                "a = ";
        cin >> inclinacao;
        cout << "" << endl;
        for (int i = 0; i < 60; i++)
        {
            sequencia3[i] = i * inclinacao;
        }
        return new Sinal(sequencia3, 60); // aqui comeca o loop infinito 
    default:
        cout << "Erro" << endl;
        return 0;
    }
    return 0;
}

Sinal* aquisicao(){
    int respostaAquisicao;
    cout << "Qual sinal voce gostaria de utilizar como entrada da sua simulacao? " << endl <<
            "1) 5+3*cos(n*pi/8)" << endl <<
            "2) constante" << endl << 
            "3) rampa" << endl << 
            "Escolha: ";
    cin >> respostaAquisicao;
    cout << "" << endl;


    Sinal* sinalAdquirido;
    
    switch (respostaAquisicao)
    {
    case 1:
        sinalAdquirido = criarSinal(respostaAquisicao);
        return sinalAdquirido;
    case 2:
        sinalAdquirido = criarSinal(respostaAquisicao);
        return sinalAdquirido;
    case 3:
        return criarSinal(respostaAquisicao);
    default:
        cout << "Erro!" << endl;
        break;
    }
    return 0;
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

ModuloRealimentado* pilotoAutomatico(double ganho){
    ModuloRealimentado *pilotoAutomaticoMR = new ModuloRealimentado(ganho);
    return pilotoAutomaticoMR;
}

void menu(){
    int resposta;
    cout << "    Simulink em C++" << endl;
    cout << "Qual simulacao voce gostaria de fazer?"<< endl << 
            "1) Piloto Automatico" << endl << 
            "2)Sua propria sequencia de operacoes"<< endl <<
            "Escolha: ";
    cin >> resposta;
    cout << "" << endl;


/********************************************************************************************/
    // switch(resposta) caso 1
    double g1 = 0;
    Sinal* s1;
    Sinal* saida1;
    ModuloRealimentado* PA;
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

/********************************************************************************************/

    switch (resposta)
    {
    case 1:
        s1 = aquisicao(); // s1 = valor de referencia
        cout << "Qual o ganho do acelerador?" << endl <<
                "g = ";
        cin >> g1;
        cout << "" << endl;

        PA = pilotoAutomatico(g1);

        saida1 = (PA->processar(s1)); 
    
        criaPlotaGrafico("Velocidade do carro",(saida1->getSequencia()), (saida1->getComprimento()));

        delete s1;
        delete saida1;

        break;
    
    case 2:
        s2 = aquisicao();
        while (continuar == 1)      
        {
            cout << "Qual operacao voce gostaria de fazer?" << endl << 
                    "1) Amplificar" << endl << 
                    "2) Somar" << endl << 
                    "3) Derivar" << endl <<
                    "4) Integrar" << endl <<
                    "Escolha: ";
            cin >> operacao;
            cout << "" << endl;  

            switch (operacao)
            {
            case 1: // Amplificar
                cout << "Qual o ganho dessa amplificacao?" << endl;
                cin >> g2;
                cout << "g = " << g2 << endl;
                amplificador->setGanho(g2);
                s2 = amplificador->processar(s2);

                delete amplificador;
                break;
            case 2: // Somar
                cout << "Informe mais um sinal para ser somado." << endl;
                s3 = aquisicao();
                s2 = somador->processar(s2, s3);

                delete somador;
                break;
            case 3: // Derivar
                s2 = derivador->processar(s2);
                
                delete derivador;
                break;
            case 4: // Integrar
                s2 = integrador->processar(s2);
                
                delete integrador;
                break;
            default:
                cout << "Erro" << endl;
                break;
            }
            cout << "O que voce quer fazer agora?" << endl <<
                    "1) Realizar mais uma operacao no resultado" << endl << 
                    "2) Imprimir o resultado para terminar" << endl <<
                    "Escolha: ";
            cin >> continuar;
            cout << "" << endl;
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