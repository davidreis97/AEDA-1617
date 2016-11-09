#pragma once
#include <string>
#include <vector>
#include "Data.h"
#include "Pessoa.h"
using namespace std;

class Utente : public Pessoa {
private:
	int periodosPorPagar;
	int aulasPorPagar;//Todas estas frequencias estao no passado. Utente nao pode pagar antes de frequentar, paga sempre no fim do mes.
public:
	float valorPagamento(float precoAula,float precoPeriodo);
	void setRelPeriodosPorPagar(int aulas, int periodos);
	void setAbsPeriodosPorPagar(int aulas, int periodos);
};