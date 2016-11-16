#pragma once
#include <string>

using namespace std;

class Pessoa {
private:
	string nome;
	int id;
	unsigned int idade;
public:
	static int ultimoId;
	int getId();
	string getNome();
	Pessoa(string nome, unsigned int idade);
	Pessoa(string nome, unsigned int idade,int id);
};