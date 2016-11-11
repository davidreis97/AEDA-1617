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
	int i;
	for (i= 0; i < this->horario.size(); i++) {
		if (data == this->horario[i]) {
			break;
		}
	}
	if (i == this->horario.size()) {
		throw DataNaoEncontrada(&data);
	}
	return (this->horario[i].getPeriodos()[periodo]->getUtentes().size());
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
	return (this->horario[i].getPeriodos()[periodo]->getEmAula());
}

void Piscina::marcarUtente(int id, bool isAula, int periodoInicial, int periodoFinal, Data data) {
	int i;
	for (i = 0; i < this->utentes.size(); i++) {
		if (this->utentes[i]->getId == id) {
			break;
		}
	}
	if (i = this->utentes.size()) {
		throw UtenteNaoEncontrado(int id);
	}
	for (int j = 0; j < this->horario.size(); j++) {
		if (this->horario[j] == data) {
			break;
		}
	}
	if (j = this->utentes.size()) {
		this->horario.push_back(data);
	}
	if (isAula) {
		if ((periodoInicial-periodoFinal) != 2) {
			printf("Quantidade de Periodos Invalidos. Aulas são de duração 1 hora.");
		}
		else {
			for (int p = periodoInicial; p < periodoFinal + 1; p++) {
				if() //verificar capacidade da piscina
				this->horario[p].getPeriodos()[p]->addEmAula();
				this->horario[p].getPeriodos()[p]->addUtente(this->utentes[i]);
			}
		}
	}
	else {
		for (int p = periodoInicial; p < periodoFinal + 1; p++) {
			//verificar capacidade da piscina
			this->horario[p].getPeriodos()[p]->addEmAula();
			this->horario[p].getPeriodos()[p]->addUtente(this->utentes[i]);
		}
	}
}