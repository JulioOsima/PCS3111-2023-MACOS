#include "Combo.h"
#include <iostream>
#include <string>

using namespace std;

// Faca os includes necessarios

//Implemente os métodos de Combo

Combo::Combo(string nome, int quantidadeMaxima):Produto(nome, 0), nomeCombo(nome), quantidadeMaxima(quantidadeMaxima) {
	// implemente
	quantidadeAtual = 0;
	vetorDeProdutosNormais = new ProdutoNormal*[quantidadeMaxima];
}

Combo::~Combo() {
	// implemente

	// deletar o o vetor do construtor
	
	delete[] vetorDeProdutosNormais;
	cout << "Combo " << this->nome << " destruido " << endl;
}

bool Combo::adicionar(ProdutoNormal *ep) {
	// implemente

	if ((quantidadeMaxima - quantidadeAtual) > 0){
		vetorDeProdutosNormais[quantidadeAtual] = ep;
		quantidadeAtual++;
		return true;
	}
	return false;
}

ProdutoNormal** Combo::getProdutosNormais() {
	// implemente

		return vetorDeProdutosNormais;
}

int Combo::getQuantidadeDeProdutosNormais() {
	// implemente

	if (quantidadeAtual > 0)
	{
		return quantidadeAtual;	
	}
	return 0;
}

void Combo::imprimir(){
	double precoCombo = 0;

	for (int j = 0; j < quantidadeAtual; j++)
	{
		precoCombo += vetorDeProdutosNormais[j]->getPreco();
	}
	

	cout << this->nome << " - " << precoCombo << " reais " << "- " << this->getQuantidadeDeProdutosNormais() << " produtos normais" << endl;
	for (int i = 1; i < (quantidadeAtual + 1); i++)
	{
		cout << "\t" << i << ": " << vetorDeProdutosNormais[i - 1]->getNome() << " - " << vetorDeProdutosNormais[i - 1]->getPreco() << " reais" << endl;
	}
}

// Veja outros metodos necessarios