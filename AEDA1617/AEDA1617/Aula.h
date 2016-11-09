#pragma once
#include "Utente.h"
#include "Professor.h"

class Periodo {
	vector<Utente *> utentes;
public:
	vector<Utente *> getUtentes();
};

class Aula : public Periodo {
private:
	Professor *professor;
};