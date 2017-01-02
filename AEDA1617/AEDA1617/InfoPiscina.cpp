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

void InfoPiscina::printModalidades() {
	for (list<string>::iterator it = this->modalidades.begin(); it != this->modalidades.end(); it++) {
		cout << (*it) << endl;
	}
}

int InfoPiscina::getDistancia() {
	return distancia;
}

bool InfoPiscina::addModalidade(string m) {
	for (list<string>::iterator it = this->modalidades.begin(); it != this->modalidades.end(); it++) {
		if (*it == m) {
			return false;
		}
	}
	this->modalidades.push_back(m);
	return true;
}

bool InfoPiscina::operator<(const InfoPiscina & p) const {
	return this->distancia > p.distancia;
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