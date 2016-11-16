#pragma once
#include "Pessoa.h"

using namespace std;
class Professor :public Pessoa{
	int aulas;
public:
	bool Professor::operator==(Professor u);
	int getNumAulas();
};