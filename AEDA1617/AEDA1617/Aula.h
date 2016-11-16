#pragma once
#include "Utente.h"
#include "Professor.h"

using namespace std;

class Periodo {
	vector<Utente *> utentes;
	int periodo;
public:
	Periodo(int periodo);
	int getPeriodo();
	vector<Utente *> *getUtentes();
	int getNumUtentes();
	void addUtente(Utente * utente);
	Professor *professor;
};

class Aula : public Periodo{
	Professor *professor;
public:
	Aula(Professor *professor, int periodo);
	Professor *getProfessor();
	void setProfessor(Professor *professor);
};