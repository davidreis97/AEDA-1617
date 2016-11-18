#include "Utente.h"
#include "Piscina.h"

using namespace std;

Piscina p(16, 2, 1.5, 5);


float Utente::valorPagamento(float precoAula, float precoPeriodo) {
	float valor = this->aulasPorPagar * precoAula + this->periodosPorPagar * precoPeriodo;
	return valor;
}

void Utente::setRelPeriodosPorPagar(int aulas, int periodos) {
	this->aulasPorPagar += aulas;
	this->periodosPorPagar += periodos;
}


void Utente::setAbsPeriodosPorPagar(int aulas, int periodos) {
	this->aulasPorPagar = aulas;
	this->periodosPorPagar = periodos;
}

Utente::Utente(string nome, unsigned int idade) :Pessoa(nome, idade) { this->aulasPorPagar = 0; this->periodosPorPagar = 0; }

Utente::Utente(string nome, unsigned int idade,int id) : Pessoa(nome, idade,id) {}

bool removeUtente(int id) {
	for (int i = 0; i < p.getUtentes.size(); i++)
		if (p.getUtentes[i].id == id) {
			p.getUtentes.erase(p.getUtentes[i]);
			return true;
		}
	return false;
}

bool Utente::operator==(Utente u) {
	if (this->getId() == u.getId()) {
		return true;
	}
	else {
		return false;
	}
}

UtenteNaoEncontrado::UtenteNaoEncontrado(int id) : id(id){}

int UtenteNaoEncontrado::getId() {
	return this->id;
}


int Utente::getPeriodosPorPagar() {
	return this->periodosPorPagar;
}


int Utente::getAulasPorPagar() {
	return this->aulasPorPagar;
}




