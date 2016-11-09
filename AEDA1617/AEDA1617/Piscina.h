#pragma once
#include "Utente.h"
#include "Professor.h"
#include "Aula.h"

class Piscina {
private:
	vector<Utente *> utentes;
	vector<Professor *> professores;
	vector<Data> Horario;
	const unsigned int periodoDia;
	float precoAula;
	float precoPeriodo;

public:
	Piscina(unsigned int periodos, float precoA, float precoP);
	vector<Utente *> getUtentes();
	vector<Professor *> getProfessores();
	bool addUtente(Utente * u);
	bool addProfessor(Professor * p);
	bool addClientes(vector<Utente* > utentes);
	bool addData(Data d);
};