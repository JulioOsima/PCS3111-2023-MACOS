#include <iostream>
#include "LocacaoResidencial.h"
#include "LocacaoComercial.h"
#include "LocacaoRegiao.h"

using namespace std;

void testeP2() {
    try{
        LocacaoResidencial* lR1 = new LocacaoResidencial("Rua A, 1423 - Prainha", 980.5, 8, 2);
        lR1->imprimir();

        lR1->setPreco(1010.0);
        cout << lR1->calcularTotal(6) << endl;

        LocacaoComercial* lC1 = new LocacaoComercial("Av. Sao Joao, 265 - Centro", 9500.0, 15, 30);
        cout << lC1->calcularTotal(-10) << endl;

        LocacaoRegiao* r1 = new LocacaoRegiao("Rua das Irmas");
        LocacaoComercial* lC2 = new LocacaoComercial("Grande Septo de Baelor", 45000.0, 1, 8200);
        r1->adicionarLocacao(lC2);
        r1->imprimir();

        LocacaoResidencial* lR2 = new LocacaoResidencial("Fosso dos Dragoes", 6520.9, 8, 5);
        r1->adicionarLocacao(lR2);
        cout << r1->calcularTotal(15) << endl;
        
        delete r1;
        delete lR1;
        delete lC1;

    }
    catch(invalid_argument *e){
    }
    

  


}