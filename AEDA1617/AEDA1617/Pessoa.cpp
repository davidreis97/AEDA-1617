#include "Pessoa.h"

int Pessoa::getId() {
	return this->id;
}

int Pessoa::getIdade() {
	return this->idade;
}

int Pessoa::ultimoId = 0;

Pessoa::Pessoa(string nome, unsigned int idade) :nome(nome),idade(idade),id(this->ultimoId++){}

Pessoa::Pessoa(string nome, unsigned int idade,int id) : nome(nome), idade(idade), id(id) {}

string Pessoa::getNome() {
	return this->nome;
}