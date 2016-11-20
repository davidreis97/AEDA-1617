#pragma once
#include "Utente.h"
#include "Professor.h"

/**
* @file   Aula.h
* @brief  Classes que definem uma aula e um periodo.
*
* Classes que definem uma aula e um periodo, cada um guardando um vetor de utentes que frequentam esse periodo, sendo que no caso da aula guarda tambem o professor responsavel por leccionar essa aula.
*/

using namespace std;

class Periodo {
	vector<Utente> utentes;
	int periodo;
public:
	Periodo(int periodo);
	int getPeriodo();
	vector<Utente> *getUtentes();
	int getNumUtentes();
	void addUtente(Utente utente);
};

class Aula : public Periodo{
	Professor professor;
public:
	Aula(Professor professor, int periodo);
	Professor getProfessor();
	void setProfessor(Professor professor);
};