#include "TestePersistenciaDeModulo.h"
#include <string>

TestePersistenciaDeModulo::TestePersistenciaDeModulo(string nomeDoArquivo){
    this->nomeDoArquivo = nomeDoArquivo;
}

TestePersistenciaDeModulo::~TestePersistenciaDeModulo(){
}

void TestePersistenciaDeModulo::interior(Modulo* moduloPrincipal, int i){
    double g;
    while (i != (vectorDeStrings->size() - 1)){
        if (vectorDeStrings->at(i) == "f"){
            break;
        }
        if (vectorDeStrings->at(i) == "I"){
            Integrador* I = new Integrador();
            moduloPrincipal->getCircuitos()->push_back(I);
        }
        if (vectorDeStrings->at(i) == "D"){
            Derivador* D = new Derivador();
            moduloPrincipal->getCircuitos()->push_back(D);
        }
        if (vectorDeStrings->at(i) == "A"){
            i++;
            g = stod(vectorDeStrings->at(i)); 
            Amplificador* A = new Amplificador(g);
            moduloPrincipal->getCircuitos()->push_back(A);
        }
        if (vectorDeStrings->at(i) == "S"){
            ModuloEmSerie* S = new ModuloEmSerie();
            interior(S, i);
        }
        if (vectorDeStrings->at(i) == "P"){
            ModuloEmParalelo* P = new ModuloEmParalelo();
            interior(P, i);
        }
        if (vectorDeStrings->at(i) == "R"){
            ModuloRealimentado* R = new ModuloRealimentado();
            interior(R, i);
        }
        
        i++;
    }
}


Modulo* TestePersistenciaDeModulo::lerDeArquivo(){
    ifstream arquivoLido;
    arquivoLido.open(nomeDoArquivo);
     if (arquivoLido.fail()){                                                        // Verifica se o arquivo foi encontrado e se pode ser aberto
        throw new invalid_argument("Erro ao abrir o arquivo");      
        arquivoLido.close(); 
        return 0;
    }

    vectorDeStrings = new vector<string>();
    int it = 0;

    while (arquivoLido){
        arquivoLido >> vectorDeStrings->at(it);
        it++;
    }
    
    int i = 0;
    if (vectorDeStrings->at(i) == "S"){
        ModuloEmSerie* S = new ModuloEmSerie();
        i++;
        interior(S, i);
    }
    if (vectorDeStrings->at(i) == "P"){
        ModuloEmParalelo* P = new ModuloEmParalelo();
        i++;
        interior(P, i);
    }
    if (vectorDeStrings->at(i) == "R"){
        ModuloRealimentado* R = new ModuloRealimentado();
        i++;
        interior(R, i);
    }
    
    
}



    /*string matrizDeModulos[20][20];
    int rows = 0;
    int cols = 0;
    string line;

    while(arquivoLido){ // Criar a matriz aqui para ler depois
        getline(arquivoLido, line);
        if (line == "S" || line == "P" || line == "R"){
            rows++;
            cols++;
            matrizDeModulos[rows][cols] = line;
        }
        
        if (line == "I" || line == "D"){
            matrizDeModulos[rows][cols] = line;
            rows++;
        }
        if (line == "A"){
            matrizDeModulos[rows][cols] = line;
            rows++;
            cols++;
        }
        if (line == "f"){
            rows++;
            cols--;
        }
        
    }
    for (int i = 1; i < rows; i++){
        for (int j = 0; i < cols; j++){
            if (matrizDeModulos[i][j] == "S"){
                ModuloEmSerie* S = new ModuloEmSerie();
                i++;
                j++;
                break;
            }
            if (matrizDeModulos[i][j] == "P"){
                ModuloEmParalelo* P = new ModuloEmParalelo();
                i++;
                j++;
                break;
            }
            if (matrizDeModulos[i][j] == "R"){
                ModuloRealimentado* R = new ModuloRealimentado();
                i++;
                j++;
                break;
            }
            if (matrizDeModulos[i][j] == "I"){
                Integrador* I = new Integrador();
                i++;
                break;
            }
            if (matrizDeModulos[i][j] == "D"){
                Derivador* D = new Derivador();
                i++;
                break;
            }
            if (matrizDeModulos[i][j] == "A"){// Como verificar q o primeiro caracter é um "A" ?
                //...                
            }
            
            
        }
        
    }
        


    if (!arquivoLido.eof()){
        throw new logic_error("Erro na leitura");
    }









}*/