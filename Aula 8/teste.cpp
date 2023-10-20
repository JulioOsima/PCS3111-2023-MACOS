#include <iostream>
#include <string>
#include "Combo.h"
#include "ProdutoNormal.h"

using namespace std;

void teste1() {
    ProdutoNormal *prod1 = new ProdutoNormal("Temaki Atum", 20);
    ProdutoNormal *prod2 = new ProdutoNormal("Shimeji", 15);
    ProdutoNormal *prod3 = new ProdutoNormal("Sashimi", 15);

    Combo *combo1 = new Combo("Sushi Executivo", 3);
    combo1->adicionar(prod1);
    combo1->adicionar(prod2);
    combo1->adicionar(prod3);

    combo1->imprimir();

    delete combo1;

}

void teste2() {

}