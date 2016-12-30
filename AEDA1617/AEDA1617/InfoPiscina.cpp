#include "InfoPiscina.h"

using namespace std;

InfoPiscina::InfoPiscina (string nome, unsigned int distancia) {
	this->nome = nome;
	this->distancia = distancia;
}

string InfoPiscina::getNome() {
	return nome;
}

list<string> InfoPiscina::getModalidades() {
	return modalidades;
}

unsigned int InfoPiscina::getDistancia() {
	return distancia;
}

void InfoPiscina::addModalidade(string m) {
	modalidades.push_back(m);
}