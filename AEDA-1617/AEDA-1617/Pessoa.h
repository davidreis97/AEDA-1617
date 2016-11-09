#pragma once
#ifndef PESSOA_H
#define PESSOA_H
#include <string>
#include "stdafx.h"
using namespace std;

class Pessoa {
private:
	string nome;
	int id;
	static int ultimoId;
};

#endif PESSOA_H