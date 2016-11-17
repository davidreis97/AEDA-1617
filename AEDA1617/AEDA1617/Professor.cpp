#include "Professor.h"

bool Professor::operator==(Professor u) {
	if (this->getId() == u.getId()) {
		return true;
	}
	else {
		return false;
	}
}

int Professor::getNumAulas() {
	return this->aulas;
}

void Professor::setNumAulas(int aulas) {
	this->aulas += aulas;
}

Professor::Professor(string nome, unsigned int idade) :Pessoa(nome, idade) { this->aulas = 0; }

Professor::Professor(string nome, unsigned int idade, int id, int aulas) : Pessoa(nome, idade, id) { this->aulas = 0; }