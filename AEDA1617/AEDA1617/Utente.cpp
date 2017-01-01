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

Utente::Utente(string nome, unsigned int idade, int id) : Pessoa(nome, idade, id) { this->aulasPorPagar = 0; this->periodosPorPagar = 0; }


bool Utente::operator==(Utente u) const {
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

void Utente::addArtigo(Artigo artigo) {
	this->artigosComprados.push_back(artigo);
}

void Utente::printArtigos() {
	cout << "O cliente " << this->getNome() << " com o id " << this->getId() << " comprou os seguintes artigos:" << endl;
	for (int i = 0; i < this->artigosComprados.size(); i++) {
		cout << "Nome do artigo: " << this->artigosComprados[i].getNome() << " Tamanho: " << this->artigosComprados[i].getTamanho() << " Quantidade: " << this->artigosComprados[i].getStock() << endl;
	}
}

vector<Artigo> Utente::getArtigos() {
	return this->artigosComprados;
}




