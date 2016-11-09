#include "stdafx.h"
#include "Utente.h"

float Utente::valorPagamento(float precoAula, float precoPeriodo) {
	float valor = this->aulasPorPagar * precoAula + this->periodosPorPagar * precoPeriodo;
	return valor;
}









