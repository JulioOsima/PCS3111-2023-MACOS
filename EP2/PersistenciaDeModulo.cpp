#include "PersistenciaDeModulo.h"

PersistenciaDeModulo::PersistenciaDeModulo(string nomeDoArquivo){
    this->nomeDoArquivo = nomeDoArquivo;
    //nomeDoArquivo = nomeDoArquivo + ".txt";
    vectorDeModulos = new vector<Modulo*>();
    
}

PersistenciaDeModulo::~PersistenciaDeModulo(){
    // deletar tudo

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

void PersistenciaDeModulo::adicionaCircuitos(Modulo* modulo, int a, int b){     // Uma vez definido o modulo mais interno, basta adicionar os circuitos ao modulo
    a++;
    for (int i = a; i < b; i++){
        if (vectorDeStrings->at(i) == "A");{
            Amplificador* amplificador = new Amplificador(2);
            modulo->adicionar(amplificador);
        }
        if (vectorDeStrings->at(i) == "D");{
            Derivador* derivador = new Derivador();
            modulo->adicionar(derivador);
        }
        if (vectorDeStrings->at(i) == "I");{
            Integrador* integrador = new Integrador();
            modulo->adicionar(integrador);
        }
        if (vectorDeStrings->at(i) == "M"){                                     // Se a string "M" for encontrada no vectorDeStrings modulo atual recebe o modulo correspondente a "M"
            modulo->adicionar(vectorDeModulos->at(k));
        }
    }
    vectorDeModulos->at(k) = modulo;                                            // Vector de modulos contendo os modulos ja criados
    k++;
    vectorDeStrings->at(a) = "M";
    a--;
    b++;
    if (b != vectorDeStrings->size()){                                          
        for (int j = a; j < vectorDeStrings->size() - a - 2; j++){              // loop para reescrever o vectorDeStrings para poder repetir o metodo
        vectorDeStrings->at(j) = vectorDeStrings->at(b);
        b++;
        }
    }
}  

void PersistenciaDeModulo::procuraModuloInterno(string moduloAtual, int a, int b){ // Encontra o modulo mais interno, e salva as posicoes relativas do inicio e fim
    for (int j = 0; vectorDeStrings->at(j) == "f"; j++){ 
        if (vectorDeStrings->at(j) == "S"){
            moduloAtual = "S";
            a = j;
        }
        if (vectorDeStrings->at(j) == "P"){
            moduloAtual = "P";
            a = j;
        }
        if (vectorDeStrings->at(j) == "R"){
            moduloAtual = "R";
            a = j;
        }
        if (vectorDeStrings->at(j) == "f"){
            b = j;
        }
    }

}

Modulo* PersistenciaDeModulo::lerDeArquivo(){
    ifstream arquivoLido;
    arquivoLido.open(nomeDoArquivo);

    if (arquivoLido.fail()){                                                       // Verifica se o arquivo foi encontrado e se pode ser aberto
        throw new invalid_argument("Erro ao abrir o arquivo");  
        arquivoLido.close(); 
        return 0;
    }
    string tipo;
    
    vectorDeStrings = new vector<string>();
    int i = 0;
    while (arquivoLido){                                        
        arquivoLido >> (*vectorDeStrings)[i];                                      // vector com as strings lidas
        i++;
    }
    if (!arquivoLido.eof()){                                    
        throw new logic_error("Erro na leitura");
    }

    string moduloAtual;
    int inicioDoModulo = 0;
    int finalDoModulo = 0;
    k = 0;
    while (finalDoModulo != vectorDeStrings->size() - 1){
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
    return vectorDeModulos->at(k);                                                  // O ultimo modulo do vectorDeModulos contem o modulo que contem todos os outros modulos e circuitos.
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

