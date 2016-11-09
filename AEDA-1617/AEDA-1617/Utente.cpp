#include "stdafx.h"


float Utente::valorPagamento(float precoAula, float precoPeriodo) {
	float valor = this->aulasPorPagar * precoAula + this->periodosPorPagar * precoPeriodo;
	return valor;
}

ostream & Utente::operator<<(ostream &os) {
	return os;
}







