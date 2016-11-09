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