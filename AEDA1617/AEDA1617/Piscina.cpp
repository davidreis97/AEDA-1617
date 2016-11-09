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
	vector<Utente *>::iterator it;
}

int  Piscina::getNumUtentesAtuais(int hora, int minutos, Data data) {
	int periodo = horaToPeriodo(hora, minutos);
	int i,utentes;
	for (i= 0; i < this->horario.size(); i++) {
		if (data == this->horario[i]) {
			break;
		}
	}
	if (i == this->horario.size()) {
		throw DataNaoEncontrada;
	}
	return (this->horario[i].getPeriodos()[periodo]->getUtentes.size());

}