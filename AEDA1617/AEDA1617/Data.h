#pragma once
#include <ostream>
#include <vector>
#include "Aula.h"

using namespace std;

class Data {
private:
	unsigned short dia;
	unsigned short mes;
	unsigned short ano;
	vector<Periodo> periodos;
	vector<Aula> aulas;
public:
	Data(unsigned short dia1, unsigned short mes1, unsigned short ano1);
	ostream &operator<<(ostream &os);
	bool operator<(Data otherdata);
	bool operator==(Data otherdata);
	unsigned short getDia();
	unsigned short getMes();
	unsigned short getAno();
	vector<Periodo> *getPeriodos();
	vector<Aula> *getAulas();
	Aula *getAula(int periodo);
	Periodo *getPeriodo(int periodo);
};

class DataInvalida {
private:
	Data *data;
public:
	Data getData();
	DataInvalida(Data* data);
};

class DataNaoEncontrada {
private:
	Data *data;
public:
	Data getData();
	DataNaoEncontrada(Data* data);
};

int horaToPeriodo(int hora, int minutos);

ostream &periodoToHora(ostream &os, int periodo);