#include "Sinal.h"
#include "Grafico.h"
#include "ModuloEmSerie.h"
#include "ModuloEmParalelo.h"
#include "ModuloRealimentado.h"
#include "Amplificador.h"
#include "Integrador.h"
#include "Derivador.h"
#include "Somador.h"
#include "PersistenciaDeModulo.h"
#include <cmath>
#include <stdexcept>
#include <list>
#include <iostream>

using namespace std;

Sinal *aquisicao(){ // Função para aquisição de sinais
    int escolha2;
    double *sequencia = new double[60];
    cout << "Qual sinal voce gostaria de utilizar como entrada da sua simulcao?" << endl
         << "1) 5+3*cos(n*pi/8)" << endl
         << "2) constante" << endl
         << "3) rampa" << endl
         << "Escolha: ";
    cin >> escolha2;
    cout << endl;
    switch (escolha2){
    case 1:
        for (int i = 0; i < 60; i++){
            sequencia[i] = 5 + 3 * cos(i*M_PI/8);
        }
        Sinal *sinalAdquirido1 = new Sinal(sequencia, 60);
        delete[] sequencia;
        return sinalAdquirido1;
    case 2:
        double c;
        cout << "Qual o valor dessa constante?" << endl
             << "C = ";
        cin >> c;
        cout << endl;
        Sinal *sinalAdquirido2 = new Sinal(c, 60);
        delete[] sequencia;
        return sinalAdquirido2;
    case 3:
        double a;
        cout << "Qual a inclinacao dessa rampa?" << endl 
             << "a = ";
        cin >> a;
        cout << endl;
        for (int i = 0; i < 60; i++){
            sequencia[i] = i * a;           
        }
        Sinal *sinalAdquirido3 = new Sinal(sequencia, 60);
        delete[] sequencia;
        return sinalAdquirido3;
    default:
        delete[] sequencia;
        return 0;
    }
}

void operacao(list<CircuitoSISO*>* listaDeOperacoes){ // Função para operações
    int escolha4;
    int escolha5 = 1;
    while (escolha5 == 1){
        cout << "Qual operacao voce gostaria de fazer?" << endl
             << "1) Amplificar" << endl
             << "2) Derivar" << endl
             << "3) Integrar" << endl
             << "Escolha: ";
        cin >> escolha4;
        cout << endl;
        switch (escolha4){
        case 1:
            double g;
            cout << "Qual o ganho dessa amplificacao?" << endl
                 << "g = ";
            cin >> g;
            cout << endl;
            Amplificador* amplificador = new Amplificador(g);
            listaDeOperacoes->push_back(amplificador);
            break;
        case 2:
            Derivador* derivador = new Derivador();
            listaDeOperacoes->push_back(derivador);
            break;
        case 3:
            Integrador* integrador = new Integrador;
            listaDeOperacoes->push_back(integrador);
            break;
        default:
            break;
        }
        cout << "O que voce quer fazer agora?" << endl
             << "1) Realizar mais uma operacao no resultado" << endl
             << "2) Imorimir o reultado" << endl
             << "Escolha: ";
        cin >> escolha5;
        cout << endl;    
    }
}

void salvarArquivo(){
    int escolha6;
    string nomeDoArquivo;
    cout << "Voce gostaria de salvar o circuito em um novo arquivo?" << endl
         << "1) Sim" << endl
         << "2) Nao" << endl
         << "Escolha: ";
    cin >> escolha6;
    cout << endl;
    switch (escolha6){
    case 1:
        cout << "Qual o nome do arquivo a ser escrito?" << endl
             << "Nome: ";
        cin >> nomeDoArquivo;
        cout << endl;

        // salvar o arquivo
        break;
    case 2:
        cout << endl;
        break;
    default:
        break;
    }

}

void simulacao2(Sinal* sinalIN){
    int escolha3;
    cout << "Qual estrutura de operacoes voce deseja ter como base?" << endl
         << "1) Operacoes em serie nao realimentadas" << endl
         << "2) Operacoes em paralelo nao realimentadas" << endl
         << "3) Operacoes em serie realimentadas" << endl
         << "Escolha: ";
    cin >> escolha3;
    cout << endl;
    switch (escolha3){
    case 1:
        // Criar objeto (modulo em serie)
        ModuloEmSerie* operacaoSNR = new ModuloEmSerie();

        operacao(operacaoSNR->getCircuitos());
        Grafico* grafico = new Grafico("Resultado Final",operacaoSNR->processar(sinalIN)->getSequencia(),operacaoSNR->processar(sinalIN)->getComprimento());
        grafico->plot();
        salvarArquivo();
        delete operacaoSNR;
        delete grafico;
        delete sinalIN;
        break;
    case 2:
        // Criar objeto (modulo em paralelo)
        ModuloEmParalelo* operacaoPNR = new ModuloEmParalelo();

        operacao(operacaoPNR->getCircuitos());
        Grafico* grafico = new Grafico("Resultado Final",operacaoPNR->processar(sinalIN)->getSequencia(),operacaoPNR->processar(sinalIN)->getComprimento());
        grafico->plot();
        salvarArquivo();
        delete operacaoPNR;
        delete grafico;
        delete sinalIN;
        break;
    case 3:
        // Criar objeto (modulo Realimentado)
        ModuloRealimentado* operacaoSR = new ModuloRealimentado();
        Grafico* grafico = new Grafico("Resultado Final",operacaoSR->processar(sinalIN)->getSequencia(),operacaoSR->processar(sinalIN)->getComprimento());
        grafico->plot();
        salvarArquivo();
        delete operacaoSR;
        delete grafico;
        delete sinalIN;
        break;
    default:
        break;
    }
    

}


void menu(){
    int escolha1;
    double *sequenciaDeEntrada = new double[60];
    Sinal* sinalDeEntrada = new Sinal(sequenciaDeEntrada, 60);
    cout << "Simulink em C++" << endl
         << "Qual simulacao gostaria de fazer?" << endl
         << "1) Circuito advindo de arquivo" << endl
         << "2) Sua propria sequencia de operacoes" << endl
         << "Escolha: ";
    cin >> escolha1;
    cout << endl;

    sinalDeEntrada = aquisicao();
    delete[] sequenciaDeEntrada;

    switch (escolha1){
    case 1: // Simulacao 1 - Circuito advindo de aquivo
        // utiliza o (sinal de entrada) no arquivo lido
        // imprimir o sinal de saida titulo: Resultado Final
        salvarArquivo();
        break;
    case 2: // Simulcao 2 - Sequencia propria de operacoes
        simulacao2(sinalDeEntrada);
         break;
    default:
        break;
    }
    delete sinalDeEntrada;
}

