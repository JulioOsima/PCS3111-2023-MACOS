#include "Sinal.h"
#include "ModuloEmSerie.h"
#include "ModuloEmParalelo.h"
#include "ModuloRealimentado.h"
#include "Amplificador.h"
#include "Integrador.h"
#include "Derivador.h"
#include "Somador.h"
#include "PersistenciaDeModulo.h"
#include <cmath>

Sinal aquisicao(){ // Função para aquisição de sinais
    int escolha2;
    cout << "Qual sinal voce gostaria de utilizar como entrada da sua simulcao?" << endl
         << "1) 5+3*cos(n*pi/8)" << endl
         << "2) constante" << endl
         << "3) rampa" << endl
         << "Escolha: ";
    cin >> escolha2;
    cout << endl;
    switch (escolha2){
    case 1:
        // Criar o sinal
        break;
    case 2:
        double c;
        cout << "Qual o valor dessa constante?" << endl
             << "C = ";
        cin >> c;
        cout << endl;
        // Criar o sinal
        break;
    case 3:
        double a;
        cout << "Qual a inclinacao dessa rampa?" << endl 
             << "a = ";
        cin >> a;
        cout << endl;
        // Criar o sinal
        break;
    default:

        break;
    }

}

Sinal operacao(){ // Função para operações
    int escolha4;
    int escolha5;
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
            // amplificar o sinal com g
            break;
        case 2:
            // derivar o sinal
            break;
        case 3:
            // Integrar o sinal
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
    return; // retornar um sinal
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
        break;
    case 2:
        cout << endl;
        break;
    default:
        break;
    }

}



void menu(){
    int escolha1;
    //Criar um sinal 
    cout << "Simulink em C++" << endl
         << "Qual simulacao gostaria de fazer?" << endl
         << "1) Circuito advindo de arquivo" << endl
         << "2) Sua propria sequencia de operacoes" << endl
         << "Escolha: ";
    cin >> escolha1;
    cout << endl;

    // (sinal de entrada) = aquisicao();

    switch (escolha1){
    case 1:
        // utiliza o (sinal de entrada) no arquivo lido
        // imprimir o sinal de saida titulo: Resultado Final
        salvarArquivo();
        break;
    case 2:
        int escolha3;
        cout << "Qual estrutura de operacoes voce deseja ter como base?" << endl
             << "1) Operacoes em serie nao realimentadas" << endl
             << "2) Operacoes em paralelo nao realimentadas" << endl
             << "3) Operacoes em serie realimentadas" << endl
             << "Escolha: ";
        cin >> escolha3;
        cout << endl;
        // 

        // imprimir o sinal de saida titulo: Resultado Final
        salvarArquivo();
        break;
    default:
        break;
    }
}

int main(){

    menu();
    return 0;
}
