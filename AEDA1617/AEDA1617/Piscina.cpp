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
	vector<Data>::iterator it = find_if(horario.begin(), horario.end(), d);

	if (it == horario.end()) {
		horario.push_back(d);
		return true;
	}
	else
		return false;
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
	return (this->horario[i].getPeriodos()[periodo]->getUtentes);
}

int Piscina::getNumUtentesAula(int hora, int minutos, Data data) {
	int periodo = horaToPeriodo(hora, minutos);
	int i, utentes;
	for (i = 0; i < this->horario.size(); i++) {
		if (data == this->horario[i]) {
			break;
		}
	}
	if (i == this->horario.size()) {
		throw DataNaoEncontrada(&data);
	}
	return (this->horario[i].getPeriodos()[periodo]->getUtentes);
}

void Piscina::marcarUtente(Utente * utente, bool isAula) {
	vector<Utente *>::iterator it  = find(this->utentes.begin(), this->utentes.end(), *(utente));
}

vector<Utente *> Piscina::ocupacaoPiscina(Data d, int x) {
	for (unsigned int i = 0; i < horario.size(); i++)
		if (horario[i] == d)
			return horario[i].getPeriodos()[x]->getUtentes();
	return {};
}