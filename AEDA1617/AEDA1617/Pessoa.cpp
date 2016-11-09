#include "Pessoa.h"

bool Pessoa::operator==(Pessoa *other) {
	if (this->id == other->getId()) {
		return true;
	}
	else {
		return false;
	}
}

int Pessoa::getId() {
	return this->id;
}

Pessoa::Pessoa(string nome, unsigned int idade) :nome(nome),idade(idade),id(ultimoId++){}

Pessoa::Pessoa(string nome, unsigned int idade,int id) : nome(nome), idade(idade), id(id) {}