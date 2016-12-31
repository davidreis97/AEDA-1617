#include "InfoPiscina.h"

using namespace std;

InfoPiscina::InfoPiscina (string nome, int distancia) {
	this->nome = nome;
	this->distancia = distancia;
}

string InfoPiscina::getNome() {
	return nome;
}

list<string> InfoPiscina::getModalidades() {
	return modalidades;
}

int InfoPiscina::getDistancia() {
	return distancia;
}

void InfoPiscina::addModalidade(string m) {
	modalidades.push_back(m);
}

bool InfoPiscina::operator<(const InfoPiscina & p) const {
	return this->distancia < p.distancia;
}

bool InfoPiscina::operator==(const InfoPiscina & p) const {
	return this->nome == p.nome;
}

InfoPiscina & InfoPiscina::operator=(const InfoPiscina & p) {
	this->nome = p.nome;
	this->modalidades = p.modalidades;
	this->distancia = p.distancia;
	return *this;
}