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

bool Piscina::addProfessor(Professor * p) {
	vector<Professor *>::iterator it = find(professores.begin(), professores.end(), p);

	if (it == professores.end()) {
		professores.push_back(u);
		return true;
	}
	else
		return false;
}

bool Piscina::addData(Data d) {
	vector<Data>::iterator it = find_if(horario.begin(), horario.end(), d.operator==);

	if (it == horario.end()) {
		horario.push_back(d);
		return true;
	}
	else
		return false;
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