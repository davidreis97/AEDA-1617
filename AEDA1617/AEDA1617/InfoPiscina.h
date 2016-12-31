#pragma once
#include <string>
#include <list>
#include <iostream>

using namespace std;

class InfoPiscina {
private:
	string nome;
	list<string> modalidades;
	int distancia;
public:
	InfoPiscina(string nome, int distancia);
	string getNome();
	list<string> getModalidades();
	int getDistancia();
	bool addModalidade(string m);
	void printModalidades();
	InfoPiscina & operator=(const InfoPiscina & p);
	bool operator==(const InfoPiscina & p) const;
	bool operator<(const InfoPiscina & p) const;
};