#include "Piscina.h"

using namespace std;
Piscina::Piscina(unsigned int periodos, float precoA, float precoP, unsigned int nMax) : periodoDia(periodos), nMaxUtentes(nMax){
	precoAula = precoA;
	precoPeriodo = precoP;
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
		professores.push_back(p);
		return true;
	}
	else
		return false;
}

bool Piscina::addData(Data d) {

	for (unsigned int i = 0; i < horario.size(); i++) {
		if ()
	}
}

int Piscina::getNumUtentesAtuais(int hora, int minutos, Data data) {
	int periodo = horaToPeriodo(hora,minutos);
	int i,utentes;
	for (i= 0; i < this->horario.size(); i++) {
		if (data == this->horario[i]) {
			break;
		}
	}
	if (i == this->horario.size()) {
		throw DataNaoEncontrada(&data);
	}
	return (this->horario[i].getPeriodos()[periodo]->getUtentes.size());
}