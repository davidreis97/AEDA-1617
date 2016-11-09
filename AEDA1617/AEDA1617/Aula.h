#pragma once
#include "Utente.h"
#include "Professor.h"

using namespace std;

class Periodo {
	vector<Utente *> utentes;
	int emAula;
public:
	vector<Utente *> getUtentes();
	void addUtente(Utente * utente);
	void addEmAula();
	int getEmAula();
	Professor *professor;
};
