#include "Pessoa.h"

int Pessoa::getId() const{
	return this->id;
}

int Pessoa::getIdade() const{
	return this->idade;
}

int Pessoa::ultimoId = 0;

Pessoa::Pessoa(string nome, unsigned int idade) :nome(nome),idade(idade),id(this->ultimoId++){}

Pessoa::Pessoa(string nome, unsigned int idade, int id) : nome(nome), idade(idade), id(id) {}


string Pessoa::getNome() const{
	return this->nome;
}


PessoaNaoEncontrada::PessoaNaoEncontrada(int id) : id(id) {}

int PessoaNaoEncontrada::getId(){
	return this->id;
}

void Pessoa::setIdade(unsigned int i) {
	this->idade = i;
}

void Pessoa::setId(int idnovo) {
	this->id = idnovo;
}