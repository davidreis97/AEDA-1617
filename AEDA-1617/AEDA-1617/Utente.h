#pragma once
#include <string>
#include <vector>
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
};