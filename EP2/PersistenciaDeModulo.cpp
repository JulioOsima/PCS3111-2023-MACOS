#include "PersistenciaDeModulo.h"

PersistenciaDeModulo::PersistenciaDeModulo(string nomeDoArquivo){
    this->nomeDoArquivo = nomeDoArquivo;
    //nomeDoArquivo = nomeDoArquivo + ".txt";
    vectorDeModulos = new vector<Modulo*>();
    
}

PersistenciaDeModulo::~PersistenciaDeModulo(){
    /*while (listaDeModulos->empty() == false){
        Modulo* p = listaDeModulos->front();
        listaDeModulos->pop_front();
        delete p;
    }
    delete listaDeModulos;*/

} 

string PersistenciaDeModulo::verificaModulo(CircuitoSISO* circuito){
    string tipo;
    double g = 0;
    
    if (dynamic_cast<Integrador*>(circuito)){
        tipo = "I";
        return tipo;
    }

    if (dynamic_cast<Derivador*>(circuito)){
        tipo = "D";
        return tipo;
    }
    Amplificador *a1 = new Amplificador(g);
    a1 = dynamic_cast<Amplificador*>(circuito);
    if (a1 != NULL){
        string ganho;
        tipo = "A ";
        tipo = tipo + to_string(a1->getGanho());
        return tipo;
    }
    return NULL;
}

void PersistenciaDeModulo::salvarEmAquivo(Modulo* mod){\
    ofstream arquivoSalvo;
    arquivoSalvo.open(nomeDoArquivo);

    if (arquivoSalvo.fail()){
        cout << "Erro ao escrever" << endl;
        throw new logic_error("erro");
        // fechar o arquivo?
    }
    if (dynamic_cast<ModuloEmSerie*>(mod)){
        arquivoSalvo << "S" << endl;
    }
    if (dynamic_cast<ModuloEmParalelo*>(mod)){
        arquivoSalvo << "P" << endl;
    }
    ModuloRealimentado* modTipoRealimentado = new ModuloRealimentado();
    modTipoRealimentado = dynamic_cast<ModuloRealimentado*>(mod);
    if (modTipoRealimentado != NULL){
        arquivoSalvo << "R" << endl;
        list<ModuloEmSerie*>::iterator k = modTipoRealimentado->getCircuitos()->begin(); // lista de modulos em serie 
        list<CircuitoSISO*>::iterator l = (*k)->getCircuitos()->begin();
        while (l != (*k)->getCircuitos()->end()){
        arquivoSalvo << verificaModulo((*l)) << endl;
        l++;
        }
        arquivoSalvo << "f" << endl;
        delete modTipoRealimentado;
        arquivoSalvo.close();
    }
    list<CircuitoSISO*>::iterator i = mod->getCircuitos()->begin();

    while (i != mod->getCircuitos()->end()){
        arquivoSalvo << verificaModulo((*i)) << endl;
        i++;
    }
    arquivoSalvo << "f";
    arquivoSalvo.close();
}

void PersistenciaDeModulo::adicionaCircuitos(Modulo* modulo, int a, int b){
    a++;
    b--;
    for (int i = a; i < b; i++){
        if (vectorDestrings->at(i) == "A");{
            Amplificador* amplificador = new Amplificador(2);
            modulo->adicionar(amplificador);
        }
        if (vectorDestrings->at(i) == "D");{
            Derivador* derivador = new Derivador();
            modulo->adicionar(derivador);
        }
        if (vectorDestrings->at(i) == "I");{
            Integrador* integrador = new Integrador();
            modulo->adicionar(integrador);
        }
        if (vectorDestrings->at(i) == "M"){
            modulo->adicionar(vectorDeModulos->at(k));
        }
    }
    vectorDeModulos->at(k) = modulo;
    k++;
    b++;
    vectorDestrings->at(a) = "M";
    a++;
    if (b - 1 != vectorDestrings->size()){
        for (int j = a; j < vectorDestrings->size() - a; j++){
        vectorDestrings->at(j) = vectorDestrings->at(b);
        b++;
        }
    }
}  

void PersistenciaDeModulo::procuraModuloInterno(string moduloAtual, int a, int b){
    for (int j = 0; vectorDestrings->at(j) == "f"; j++){ // Encontra o modulo mais interno
        if (vectorDestrings->at(j) == "S"){
            moduloAtual = "S";
            a = j;
        }
        if (vectorDestrings->at(j) == "P"){
            moduloAtual = "P";
            a = j;
        }
        if (vectorDestrings->at(j) == "R"){
            moduloAtual = "R";
            a = j;
        }
        if (vectorDestrings->at(j) == "f"){
            b = j;
        }
    }

}

Modulo* PersistenciaDeModulo::lerDeArquivo(){
    ifstream arquivoLido;
    arquivoLido.open(nomeDoArquivo);

    if (arquivoLido.fail()){ // Verifica se o arquivo foi encontrado e se pode ser aberto
        throw new invalid_argument("Erro ao abrir o arquivo");
        arquivoLido.close(); 
        return 0;
    }
    string tipo;
    
    vectorDestrings = new vector<string>();
    int i = 0;
    while (arquivoLido){ // enquanto nao é nem failbit nem badbit
        arquivoLido >> (*vectorDestrings)[i];
        i++;
    }
    if (!arquivoLido.eof()){
        throw new logic_error("Erro na leitura");
    }

    string moduloAtual;
    int inicioDoModulo = 0;
    int finalDoModulo = 0;
    k = 0;
    while (finalDoModulo != vectorDestrings->size()){
        procuraModuloInterno(moduloAtual, inicioDoModulo, finalDoModulo);
        if (moduloAtual == "S"){
            ModuloEmSerie* moduloEmSerie = new ModuloEmSerie();
            adicionaCircuitos(moduloEmSerie, inicioDoModulo, finalDoModulo);
        }
        if (moduloAtual == "P"){
            ModuloEmParalelo* moduloEmParalelo = new ModuloEmParalelo();
            adicionaCircuitos(moduloEmParalelo, inicioDoModulo, finalDoModulo);
        }
        if (moduloAtual == "R"){
            ModuloRealimentado* moduloRealimentado = new ModuloRealimentado();
            adicionaCircuitos(moduloRealimentado, inicioDoModulo, finalDoModulo);
        }
    }
    k--;
    return vectorDeModulos->at(k);
    /*arquivoLido >> tipo;
    numeroDeModulos = 0;
    quantidadeTotal = 0;
    if (tipo == "S"){
        ModuloEmSerie* moduloEmSerie = new ModuloEmSerie();
        vectorDeModulos->push_back(moduloEmSerie);
        numeroDeModulos++;
        quantidadeTotal++;
        }
    if (tipo == "P"){
        ModuloEmParalelo* moduloEmParalelo = new ModuloEmParalelo();
        vectorDeModulos->push_back(moduloEmParalelo);
        numeroDeModulos++;
        quantidadeTotal++;
    }
    if (tipo == "R"){
        ModuloRealimentado* moduloRealimentado = new ModuloRealimentado();
        vectorDeModulos->push_back(moduloRealimentado);
        numeroDeModulos++;
        quantidadeTotal++;
    }
    
    while (arquivoLido){ // enquanto ele n é nem failbit nem badbit
        arquivoLido >> tipo; // usar o get line para o caso do amplficador
        verificaTipo(tipo);
        tipo = "";
        quantidadeTotal++;
    }*/
}

