#pragma once
#include "Pessoa.h"

using namespace std;
class Professor :public Pessoa{
	int aulas;
public:
	Professor(string nome, unsigned int idade);
	Professor(string nome, unsigned int idade, int id, int aulas);
	bool Professor::operator==(Professor u);
	int getNumAulas();
	void setNumAulas(int aulas);
};

