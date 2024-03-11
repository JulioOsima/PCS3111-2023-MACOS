#include <iostream>
#include <string>
#include "Modulo.h"
#include "ModuloEmSerie.h"
#include "ModuloEmParalelo.h"
#include "ModuloRealimentado.h"

#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

class TestePersistenciaDeModulo{
private:
    string nomeDoArquivo;
    vector<string>* vectorDeStrings; 
    void interior(Modulo* moduloPrincipal, int i);
public:
    TestePersistenciaDeModulo(string nomeDoArquivo);
    ~TestePersistenciaDeModulo();
    void salvarEmArquivo(Modulo *mod);
    Modulo* lerDeArquivo();
};



