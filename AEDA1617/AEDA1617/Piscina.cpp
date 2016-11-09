#include "Piscina.h"


Piscina::Piscina(unsigned int periodos, float precoA, float precoPeriodo) : periodoDia(periodos){
	precoAula = precoA;
	precoPeriodo = precoPeriodo;
}

vector<Utente *> Piscina::getUtentes() {
	return utentes;
}

vector<Professor *> Piscina::getProfessores() {
	return professores;
}

bool Piscina::addUtente(Utente * u) {
	vector<Utente *>::iterator it = find(utentes.begin(), utentes.end(), u);

	if (it == utentes.end()) {
		utentes.push_back(u);
		return true;
	}
	else
		return false;
}