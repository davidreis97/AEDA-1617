#pragma once
#include <string>
#include <list>

using namespace std;

class InfoPiscina {
private:
	string nome;
	list<string> modalidades;
	unsigned int distancia;
public:
	InfoPiscina(string nome, unsigned int distancia);
	string getNome();
	list<string> getModalidades();
	unsigned int getDistancia();
	void addModalidade(string m);
};