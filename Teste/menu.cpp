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

//
//  Verificar os deletes 
//  Adicionar o metodo do modulo realimentado                                                       - Aparentemente resolvido
//  Adicionar a funcao de ler modulo de arquivo                                                     - Aparentemente resolvido
//  Verificar os possiveis erros de input
//  Formatar o codigo: identaçao e retirar os comentarios inuteis e adicionar os comentarios uteis
//  adicionar os try and catch toda vez que for criar um sinal
//

Sinal *aquisicao(Sinal* sinal){ // Função para aquisição de sinais
    int escolha2;
    double *sequencia = new double[60];                                                     // Deletado em: L43 (case 1), L53 (case 2), L66 (case 3)
    cout << "Qual sinal voce gostaria de utilizar como entrada da sua simulacao?" << endl
         << "1) 5+3*cos(n*pi/8)" << endl
         << "2) constante" << endl
         << "3) rampa" << endl
         << "Escolha: ";
    cin >> escolha2;
    cout << endl;
    switch (escolha2){
    case 1:{
        for (int i = 0; i < 60; i++){
            sequencia[i] = 5 + 3 * cos(i*M_PI/8);
        }
        Sinal *sinalAdquirido1 = new Sinal(sequencia, 60);                                  // Deletado em: L45
        sinal = sinalAdquirido1;
        delete[] sequencia;
        delete sinalAdquirido1;
        return sinal;
    }
    case 2:{
        double c;
        cout << "Qual o valor dessa constante?" << endl
             << "C = ";
        cin >> c;
        cout << endl;
        Sinal *sinalAdquirido2 = new Sinal(c, 60);                                          // Deletado em: L57
        sinal = sinalAdquirido2;
        delete[] sequencia;
        delete sinalAdquirido2;
        return sinal;
    }    
    case 3:{
        double a;
        cout << "Qual a inclinacao dessa rampa?" << endl 
             << "a = ";
        cin >> a;
        cout << endl;
        for (int i = 0; i < 60; i++){
            sequencia[i] = i * a;           
        }
        Sinal *sinalAdquirido3 = new Sinal(sequencia, 60);                                  // Deletado em: L57
        sinal = sinalAdquirido3;
        delete[] sequencia;
        delete sinalAdquirido3;
        return sinal;

    }    
    default:
        //delete[] sequencia;
        return 0;
    }   
}

void operacao(Modulo *modulo){ // Função para operações, adiociona as operacoes à lista do modulo
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
        case 1:{
            double g;
            cout << "Qual o ganho dessa amplificacao?" << endl
                 << "g = ";
            cin >> g;
            cout << endl;
            Amplificador* amplificador = new Amplificador(g);                               // Deletado em:
            modulo->adicionar(amplificador); // !!!!!!!!
            break;
        }
        case 2:{
            Derivador* derivador = new Derivador();                                         // Deletado em:
            modulo->adicionar(derivador);
            break;
        }
        case 3:{
            Integrador* integrador = new Integrador;                                        // Deletado em:
            modulo->adicionar(integrador);
            break;
        }
        default:
            break;
        }
        cout << "O que voce quer fazer agora?" << endl
             << "1) Realizar mais uma operacao no resultado" << endl
             << "2) Imprimir o resultado" << endl
             << "Escolha: ";
        cin >> escolha5;
        cout << endl;    
    }
}

void save(Modulo *modulo){
    int escolha6;
    string nomeDoArquivo;
    cout << "Voce gostaria de salvar o circuito em um novo arquivo?" << endl
         << "1) Sim" << endl
         << "2) Nao" << endl
         << "Escolha: ";
    cin >> escolha6;
    cout << endl;
    
    switch (escolha6){
    case 1:{
        cout << "Qual o nome do arquivo a ser escrito?" << endl
         << "Nome: ";
        cin >> nomeDoArquivo;
        cout << endl;
        PersistenciaDeModulo* save = new PersistenciaDeModulo(nomeDoArquivo);               // Deletado em: L145;
        try {
            save->salvarEmArquivo(modulo);
            delete save;
        } 
        catch (logic_error *e){
        }       
        break;
    }    
    case 2:
        delete modulo;
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
    case 1:{
        ModuloEmSerie* operacaoSNR = new ModuloEmSerie();                                   //Deletado em: L180

        operacao(operacaoSNR);
        try{
            operacaoSNR->processar(sinalIN)->imprimir("Resultado Final");
        }
        catch(logic_error *e){   
        }
        save(operacaoSNR);
        delete operacaoSNR; 
        // delete sinalIN; implica double freed variable
        break;
    }
    case 2:{
        ModuloEmParalelo* operacaoPNR = new ModuloEmParalelo();                             // Deletado em: L193

        operacao(operacaoPNR);
        try{
            operacaoPNR->processar(sinalIN)->imprimir("Resultado Final");
        }
        catch(logic_error *e){
        }
        save(operacaoPNR);
        delete operacaoPNR;
        //delete sinalIN;
        break;
    }
    case 3:{
        ModuloRealimentado* operacaoSR = new ModuloRealimentado();                          // Deletado em: L198
        ModuloEmSerie* moduloEmSerieRealimentado = new ModuloEmSerie();                     // Deletado em: ModuloRealimentado.cpp L14
        
        operacao(moduloEmSerieRealimentado);
        operacaoSR->adicionar(moduloEmSerieRealimentado);
        try{
            operacaoSR->processar(sinalIN)->imprimir("Resultado Final");
        }
        catch(logic_error *e){
        }
        save(operacaoSR);
        delete operacaoSR;
        //delete sinalIN;
        break;
    }
    default:
        break;
    }
}


void menu(){
    int escolha1 = 0;
    double *sequenciaDeEntrada = new double[60];                                            // Deletado em: L230
    Sinal* sinalDeEntrada = new Sinal(sequenciaDeEntrada, 60);                              // Deletado em: L263
    cout << "Simulink em C++" << endl
         << "Qual simulacao gostaria de fazer?" << endl
         << "1) Circuito advindo de arquivo" << endl
         << "2) Sua propria sequencia de operacoes" << endl
         << "Escolha: ";
    cin >> escolha1;
    cout << endl;

    sinalDeEntrada = aquisicao(sinalDeEntrada);
    delete[] sequenciaDeEntrada;

    switch (escolha1){
    case 1:{ // Simulacao 1 - Circuito advindo de aquivo
        string nomeDoArquivo;
        cout << "Qual o nome do arquivo a ser lido?" << endl
             << "Nome: ";
        cin >> nomeDoArquivo;
        cout << endl;
        PersistenciaDeModulo* arquivoParaLer = new PersistenciaDeModulo(nomeDoArquivo);     // Deletado em: L253
        try{
            try{
                arquivoParaLer->lerDeArquivo()->processar(sinalDeEntrada)->imprimir("Resultado Final");
                save(arquivoParaLer->lerDeArquivo());
            }
            catch(logic_error *e){
            }   
        }
        catch(invalid_argument *e){
        }
        delete arquivoParaLer; //verificar 
        break;
    }
    case 2:{ // Simulcao 2 - Sequencia propria de operacoes
        simulacao2(sinalDeEntrada);
        break;  
    }
    default:
        break;
    }
    delete sinalDeEntrada;
}
