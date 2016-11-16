#pragma once
#include <string>
#include <vector>
#include "Pessoa.h"
using namespace std;

class Utente : public Pessoa {
private:
	int periodosPorPagar;
	int aulasPorPagar; //Todas estas frequencias estao no passado. Utente nao pode pagar antes de frequentar, paga sempre no fim do mes.
public:
	Utente(string nome, unsigned int idade);
	Utente(string nome, unsigned int idade,int id);
	bool operator==(Utente u);
	float valorPagamento(float precoAula,float precoPeriodo);
	void setRelPeriodosPorPagar(int aulas, int periodos);
	void setAbsPeriodosPorPagar(int aulas, int periodos);
	int getPeriodosPorPagar();
	int getAulasPorPagar();
};

class UtenteNaoEncontrado {
	int id;
public:
	UtenteNaoEncontrado(int id);
	int getId();
};