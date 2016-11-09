#pragma once
#include "Utente.h"
#include "Professor.h"

class Periodo {
	vector<Utente *> utentes;
};

class Aula : public Periodo {
private:
	Professor *professor;
};