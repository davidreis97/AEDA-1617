#pragma once
#include "Utente.h"
#include "Professor.h"
#include "Data.h"
#include <algorithm>
#include <iostream>

using namespace std;
class Piscina {
private:
	vector<Utente> utentes;
	vector<Professor> professores;
	vector<Data> horario;
	const unsigned int periodoDia;
	float precoAula;
	float precoPeriodo;
	const unsigned int nMaxUtentes;
public:
	Piscina(unsigned int periodos, float precoA, float precoP, unsigned int nMax);
	vector<Utente> getUtentes();
	vector<Professor> getProfessores();
	bool addUtente(Utente u);
	bool addProfessor(Professor p);
	bool addData(Data d);
	int	 getNumUtentesAula(int periodo, Data data);
	void marcarUtente(int id, bool isAula, int periodoInicial, int periodoFinal, Data data);
	int  getNumUtentesAtuais(int periodo, Data data);
	void pagarUtente(int id, int mes);
	void printOcupacaoPiscina(Data d,int periodo);
	void printFrequenciaUtente(int id);
	void printProfessor(int id);
	void printDia(Data data);
	bool newAula(Data data, int periodo);
};

class PiscinaCheia {
	int nMaxUtentes;
public:
	PiscinaCheia(int nMaxUtentes);
	int getNMaxUtentes();
};
