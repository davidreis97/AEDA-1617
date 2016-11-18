#pragma once
#include <ostream>
#include <vector>
#include "Aula.h"

/**
* @file   Data.h
* @date   November, 2016
* @brief  Classe que define uma data.
*
* Classe que define uma data, contendo informacao sobre todos os periodos e aulas existentes nesse dia.
*/

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
	friend ostream & operator<<(ostream &os, Data& data);
	bool operator<(Data otherdata);
	bool operator==(Data otherdata);
	unsigned short getDia();
	unsigned short getMes();
	unsigned short getAno();
	vector<Periodo> *getPeriodos();
	vector<Aula> *getAulas();
	void addPeriodo(int i);
	void addAula(int i, Professor* prof);
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