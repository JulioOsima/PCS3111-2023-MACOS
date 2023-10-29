#ifndef PRODUTOINDISPONIVEL_H
#define PRODUTOINDISPONIVEL_H

#include <iostream>
#include <stdexcept>
using namespace std;

class ProdutoIndisponivel : public logic_error{
private:
    /* data */
    string arg;


public:
    ProdutoIndisponivel(string arg);
    ~ProdutoIndisponivel();
};

#endif