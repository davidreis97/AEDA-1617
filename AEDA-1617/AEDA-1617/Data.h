#pragma once
#ifndef DATA_H
#define DATA_H
#include <ostream>
#include "stdafx.h"
using namespace std;

class Data {
private:
	unsigned short dia;
	unsigned short mes;
	unsigned short ano;
	vector<Periodo> periodos;
public:
	Data(unsigned short dia1, unsigned short mes1, unsigned short ano1);
	ostream &operator<<(ostream &os);
};

class DataInvalida {
private:
	Data *data;
public:
	Data getData();
	DataInvalida(Data* data);
};

#endif DATA_H