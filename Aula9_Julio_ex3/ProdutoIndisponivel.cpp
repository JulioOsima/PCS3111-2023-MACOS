#include "ProdutoIndisponivel.h"
#include <iostream>
#include <string>

using namespace std;


ProdutoIndisponivel::ProdutoIndisponivel(string arg):logic_error("Produto indisponivel"), arg(arg){

}

ProdutoIndisponivel::~ProdutoIndisponivel(){
    
}