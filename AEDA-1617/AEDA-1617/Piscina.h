#pragma once
#include "Utente.h"
#include "Professor.h"
#include "Aula.h"

class Piscina {
private:
	vector<Utente *> utentes;
	vector<Professor *> professores;
	vector<Periodo> periodos;
};