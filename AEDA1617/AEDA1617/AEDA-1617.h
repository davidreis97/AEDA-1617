#pragma once
#include "Utente.h"
#include "Piscina.h"
#include <sstream>
#include <vector>
#include <fstream>
#include <string>

void menuInicial();

void menuPiscina(Piscina *p);

void menuUtentes(Piscina *p);

void menuProfessores(Piscina *p);

void menuHorario(Piscina *p);

void menuMarcacoes(Piscina *p);