#include "Utente.h"
#include "Piscina.h"

using namespace std;

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

bool Utente::operator==(Utente u) {
	if (this->getId() == u.getId()) {
		return true;
	}
	else {
		return false;
	}
}

int Utente::getPeriodosPorPagar() {
	return this->periodosPorPagar;
}


int Utente::getAulasPorPagar() {
	return this->aulasPorPagar;
}




