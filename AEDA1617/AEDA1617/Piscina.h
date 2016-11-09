#pragma once
#include "Utente.h"
#include "Professor.h"
#include "Aula.h"
#include "Data.h"
#include <algorithm>

class Piscina {
private:
	vector<Utente *> utentes;
	vector<Professor *> professores;
	vector<Data> horario;
	const unsigned int periodoDia;
	float precoAula;
	float precoPeriodo;

public:
	Piscina(unsigned int periodos, float precoA, float precoP);
	vector<Utente *> getUtentes();
	vector<Professor *> getProfessores();
	bool addUtente(Utente * u);
	bool addProfessor(Professor * p);
	bool addUtentes(vector<Utente* > utentes);
	bool addData(Data d);
	int	 getNumUtentesAula(int hora, int minutos, Data data);
	int  getNumUtentesAtuais(int hora, int minutos, Data data);
	void pagarMesUtente(int id);
	void pagarMesUtente(string nome);
};

bool dataIgual(Data d);