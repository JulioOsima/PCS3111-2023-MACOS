#include "PersistenciaDeModulo.h"

PersistenciaDeModulo::PersistenciaDeModulo(string nomeDoArquivo){
    this->nomeDoArquivo = nomeDoArquivo;
    //nomeDoArquivo = nomeDoArquivo + ".txt";
    
    
}

PersistenciaDeModulo::~PersistenciaDeModulo(){
    /*int i = 0;
    delete vectorDeStrings;
    while (!vectorDeModulos->empty()){
        Modulo* m = vectorDeModulos->back();
        vectorDeModulos->pop_back();
        delete m;
        i++;
    }
    delete vectorDeModulos;
    */
    delete vectorDeStrings;
    delete vectorDeModulos;
    
    
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
    Amplificador *a1 = new Amplificador(g); // deletado em PersistenciaDeModulo.cpp l46
    a1 = dynamic_cast<Amplificador*>(circuito);
    if (a1 != NULL){
        string ganho;
        tipo = "A ";
        tipo = tipo + to_string(a1->getGanho());
        delete a1;
        return tipo;
    }
    return NULL;
}

void PersistenciaDeModulo::salvarEmArquivo(Modulo* mod){
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
    ModuloRealimentado* modTipoRealimentado = new ModuloRealimentado(); // deletado em PersistenciaDeModulo.cpp l76
    modTipoRealimentado = dynamic_cast<ModuloRealimentado*>(mod);
    if (modTipoRealimentado != NULL){
        arquivoSalvo << "R" << endl;
        
        list<CircuitoSISO*>::iterator l = modTipoRealimentado->getCircuitos()->begin();
        while (l != modTipoRealimentado->getCircuitos()->end()){
        arquivoSalvo << verificaModulo((*l)) << endl;
        l++;
        }
        arquivoSalvo << "f" << endl;
        
        arquivoSalvo.close();
        return; // para dizer q a funcao acaba aqui
    }
    delete modTipoRealimentado;
    list<CircuitoSISO*>::iterator i = mod->getCircuitos()->begin();

    while (i != mod->getCircuitos()->end()){
        arquivoSalvo << verificaModulo((*i)) << endl;
        i++;
    }
    arquivoSalvo << "f";
    arquivoSalvo.close();
    

    // deletar os objetos criados
}

void PersistenciaDeModulo::adicionaCircuitos(Modulo* modulo, int a, int b){         // Uma vez definido o modulo mais interno, basta adicionar os circuitos ao modulo
    a++;
    for (int i = a; i < b; i++){
        if (vectorDeStrings->at(i) == "A"){
            Amplificador* amplificador = new Amplificador(2);
            modulo->adicionar(amplificador);
        }
        if (vectorDeStrings->at(i) == "D"){
            Derivador* derivador = new Derivador();
            modulo->adicionar(derivador);
        }
        if (vectorDeStrings->at(i) == "I"){
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

void PersistenciaDeModulo::procuraModuloInterno(string moduloAtual, int a, int b){  // Encontra o modulo mais interno, e salva as posicoes relativas do inicio e fim
    for (int j = 0; vectorDeStrings->at(j) == "f"; j++){ // n esta considerando que os modulos nao estao necessariamente todos um dentro do outro
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

void PersistenciaDeModulo::interior(Modulo* moduloPrincipal, int i){
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



Modulo* PersistenciaDeModulo::lerDeArquivo(){
    ifstream arquivoLido;
    vectorDeModulos = new vector<Modulo*>();
    arquivoLido.open(nomeDoArquivo);

    if (arquivoLido.fail()){                                                        // Verifica se o arquivo foi encontrado e se pode ser aberto
        throw new invalid_argument("Erro ao abrir o arquivo");      
        arquivoLido.close(); 
        return 0;
    }
    string tipo;

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
        return S;
    }
    if (vectorDeStrings->at(i) == "P"){
        ModuloEmParalelo* P = new ModuloEmParalelo();
        i++;
        interior(P, i);
        return P;
    }
    if (vectorDeStrings->at(i) == "R"){
        ModuloRealimentado* R = new ModuloRealimentado();
        i++;
        interior(R, i);
        return R;
    }
    
    
    /*vectorDeStrings = new vector<string>();
    string matrizDeModulos[10][10];
    int it;

    while(arquivoLido){ // Criar a matriz aqui para ler depois
        arquivoLido >> vectorDeStrings->at(it);
        it++;
    }
    if (!arquivoLido.eof()){
        throw new logic_error("Erro na leitura");
    }
    // Tipos de modulos
    // R - Realimentado
    // S - Serie
    // P - Paralelo

    int i, j;
    i = 0;
    j = 0;
    it = 1;
    matrizDeModulos[i][j] = vectorDeStrings->at(it);
    i++;
    j++;
    while (it != vectorDeStrings->size() - 1){
        if (vectorDeStrings->at(it) == "S" || vectorDeStrings->at(it) == "P" || vectorDeStrings->at(it) == "R"){
            matrizDeModulos[i][j] = vectorDeStrings->at(it);
            i++;
            j++;
            it++;
            break;
        }
        if (vectorDeStrings->at(it) == "I" || vectorDeStrings->at(it) == "D"){
            matrizDeModulos[i][j] = vectorDeStrings->at(it);
            i++;
            it++;
            break;
        }
        
        if (vectorDeStrings->at(i) == "f"){
            i++;
            j--;
            break;
        }
    }
    
    */







   /* vectorDeStrings = new vector<string>();     // Deletado no destrutor
    int i = 0;
    while (arquivoLido){                                        
        arquivoLido >> (*vectorDeStrings)[i];                                       // vector com as strings lidas
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
        procuraModuloInterno(moduloAtual, inicioDoModulo, finalDoModulo); // Altera o inicio do moduloy
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

