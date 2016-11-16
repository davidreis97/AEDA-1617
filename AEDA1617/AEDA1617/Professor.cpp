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