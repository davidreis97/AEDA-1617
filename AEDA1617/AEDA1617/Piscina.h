#pragma once
#include "Utente.h"
#include "Professor.h"
#include "Data.h"
#include <algorithm>
using namespace std;
class Piscina {
private:
	vector<Utente *> utentes;
	vector<Professor *> professores;
	vector<Data> horario;
	const unsigned int periodoDia;
	float precoAula;
	float precoPeriodo;
	const unsigned int nMaxUtentes;

public:
	Piscina(unsigned int periodos, float precoA, float precoP, unsigned int nMax);
	vector<Utente *> getUtentes();
	vector<Professor *> getProfessores();
	bool addUtente(Utente * u);
	bool addProfessor(Professor * p);
	bool addData(Data d);
	void marcarUtente(Utente * utente, bool isAula);
	int	 getNumUtentesAula(int hora, int minutos, Data data);
	int  getNumUtentesAtuais(int hora, int minutos, Data data);
	void pagarMesUtente(int id);
	void pagarMesUtente(string nome);
	vector<Utente *> ocupacaoPiscina(Data d, int x);
};

