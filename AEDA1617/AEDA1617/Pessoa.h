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
};