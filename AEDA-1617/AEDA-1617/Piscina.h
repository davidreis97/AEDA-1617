#pragma once
#ifndef PISCINA_H
#define PISCINA_H
#include "stdafx.h"

class Piscina {
private:
	vector<Utente *> utentes;
	vector<Professor *> professores;
	vector<Periodo> periodos;
};

#endif PISCINA_H