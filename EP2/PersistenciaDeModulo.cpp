#include "PersistenciaDeModulo.h"

PersistenciaDeModulo::PersistenciaDeModulo(string nomeDoArquivo){
    this->nomeDoArquivo = nomeDoArquivo;
    nomeDoArquivo = nomeDoArquivo + ".txt"; // verificar
    listaDeModulos = new list<Modulo*>;
}

PersistenciaDeModulo::~PersistenciaDeModulo(){
    while (listaDeModulos->empty() == false){
        Modulo* p = listaDeModulos->front();
        listaDeModulos->pop_front();
        delete p;
    }
    delete listaDeModulos;

} 
string PersistenciaDeModulo::verificaModulo(CircuitoSISO* circuito){
    string tipo;
    double g;
    Amplificador *a1 = new Amplificador(g);
    if (dynamic_cast<Integrador*>(circuito)){
        tipo = "I";
        return tipo;
    }

    if (dynamic_cast<Derivador*>(circuito)){
        tipo = "D";
        return tipo;
    }
    
    a1 = dynamic_cast<Amplificador*>(circuito);
    if (a1 != NULL){
        string ganho;
        tipo = "A";
        tipo = tipo + to_string(a1->getGanho());
        delete a1;
        return tipo;
    }
}

void PersistenciaDeModulo::salvarEmAquivo(Modulo* mod){
    ofstream arquivoSalvo;
    arquivoSalvo.open(nomeDoArquivo);

    if (arquivoSalvo.fail()){
        cout << "Erro ao escrever" << endl;
        throw new logic_error("erro");
    }

    if (dynamic_cast<ModuloEmSerie*>(mod)){
        arquivoSalvo << "S" << endl;
    }
    if (dynamic_cast<ModuloEmParalelo*>(mod)){
        arquivoSalvo << "P" << endl;
    }
    if (dynamic_cast<ModuloRealimentado*>(mod)){
        arquivoSalvo << "R" << endl;
    }

    list<CircuitoSISO*>::iterator i = mod->getCircuitos()->begin();

    while (i != mod->getCircuitos()->end()){
        arquivoSalvo << verificaModulo((*i)) << endl;
    }
    arquivoSalvo << "f";
    arquivoSalvo.close();
}

Modulo* PersistenciaDeModulo::lerArquivo( ){
    // Adicionar metodo
    ifstream arquivoLido;
    arquivoLido.open(nomeDoArquivo);

    if (arquivoLido.fail()){ // Verifica se o arquivo foi encontrado e se pode ser aberto
        cout << "Arquivo não encontrado" << endl;
        arquivoLido.close();
        return 0;
    }

    list<Modulo*>::iterator i = listaDeModulos->begin();
    while (arquivoLido){ // enquanto ele n é nem failbit nem badbit

        
    }
    

    
}