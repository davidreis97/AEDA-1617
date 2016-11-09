#pragma once
#ifndef UTENTE_H
#define UTENTE_H
#include <string>
#include <vector>
#include "stdafx.h"

using namespace std;


struct Frequencia {
	Data data;
	int periodoInicial;
	int periodoFinal;
	bool aluno;
};

class Utente : public Pessoa {
private:
	int periodosPorPagar;
	int aulasPorPagar;//Todas estas frequencias estao no passado. Utente nao pode pagar antes de frequentar, paga sempre no fim do mes.
	vector<Frequencia> historico;
public:
	float valorPagamento(float precoAula,float precoPeriodo);
	ostream & operator<<(ostream &os);
};

#endif UTENTE_H