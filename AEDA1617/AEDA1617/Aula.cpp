#include "Utente.h";
#include "Aula.h"

using namespace std;
vector<Utente> *Periodo::getUtentes(){
	return &(this->utentes);
}


Professor Aula::getProfessor() {
	return this->professor;
}

void Aula::setProfessor(Professor professor) {
	this->professor = professor;
}

int Periodo::getPeriodo() {
	return this->periodo;
}

Aula::Aula(Professor professor, int periodo) : professor(professor), Periodo(periodo) {};

Periodo::Periodo(int periodo): periodo(periodo) {}

int Periodo::getNumUtentes() {
	return this->utentes.size();
}

void Periodo::addUtente(Utente utente) {
	this->utentes.push_back(utente);
}

void Periodo::deleteUtente(int id) {
	for (vector<Utente>::iterator it = this->utentes.begin(); it != this->utentes.end();) {
		if ((*it).getId() == id) {
			this->utentes.erase(it);
		}
		else {
			it++;
		}
	}
}