#include "Sinal.h"
#include <cmath>
#include "Somador.h"
#include "Derivador.h"
#include "Piloto.h"
#include "ModuloRealimentado.h"
#include "Grafico.h"
#include <iostream>
#include <string>

using namespace std;

Sinal* criarSinal(int tipo);

Sinal* aquisicao();

void criaPlotaGrafico(string nome, double *sequencia, int comprimento);

Piloto* piloto(double ganhop);

void menu(); // Preciso declarar as outras funções aqui???

int main() {
    menu();
    return 0;
}