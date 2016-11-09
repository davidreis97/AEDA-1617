#pragma once
#ifndef PISCINA_H
#define PISCINA_H
#include "stdafx.h"

class Piscina {
private:
	vector<Utente *> utentes;
	vector<Professor *> professores;
	vector<Data> Horario;
	unsigned int periodoDia;
public:
	Piscina();
	Piscina(unsigned int periodos);
	vector<Utente *> getUtentes();
	vector<Professor *> getProfessores();
	bool addUtente(Utente * u);
	bool addProfessor(Professor * p);
	bool addClientes(vector<Utente* > utentes);
	bool addData(Data d);
};