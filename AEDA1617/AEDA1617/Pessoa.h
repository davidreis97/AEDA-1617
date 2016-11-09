#pragma once
#include <string>

using namespace std;

class Pessoa {
private:
	string nome;
	int id;
	unsigned int idade;
	static int ultimoId;
public:
	bool operator==(Pessoa *other);
	int getId();
	Pessoa(string nome, unsigned int idade);
	Pessoa(string nome, unsigned int idade,int id);
};