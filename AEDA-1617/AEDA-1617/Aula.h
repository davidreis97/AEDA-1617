#pragma once
#ifndef AULA_H
#define AULA_H
#include "stdafx.h"

class Periodo {
	vector<Utente *> utentes;
};

class Aula : public Periodo {
private:
	Professor *professor;
};

#endif AULA_H