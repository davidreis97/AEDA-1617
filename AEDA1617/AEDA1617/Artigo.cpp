#include "Artigo.h"

using namespace std;

Artigo::Artigo(string nome, int stock, string tamanho) : nome(nome), stock(stock) {
	if (tamanho == "XXS") {
		this->tamanho = "XXS";
	}
	else if (tamanho == "XS") {
		this->tamanho = "XS";
	}
	else if (tamanho == "S") {
		this->tamanho = "S";
	}
	else if (tamanho == "M") {
		this->tamanho = "M";
	}
	else if (tamanho == "L") {
		this->tamanho = "L";
	}
	else if (tamanho == "XL") {
		this->tamanho = "XL";
	}
	else if (tamanho == "XXL") {
		this->tamanho = "XXL";
	}
	else if (tamanho == "") {
		this->tamanho = "";
	}
	else {
		throw TamanhoInvalido(tamanho);
	}
}

bool Artigo::addStock(int stock) {
	if (this->stock + stock >= 0) {
		this->stock += stock;
		return true;
	}
	else {
		return false;
	}
}

int Artigo::getStock() {
	return this->stock;
}

string Artigo::getNome() {
	return this->nome;
}

string Artigo::getTamanho() {
	return this->tamanho;
}

bool Artigo::operator<(Artigo art) const {
	if (this->nome < art.nome) {
		return true;
	}
	else if (this->nome == art.nome) {
		if (this->tamanho < art.tamanho) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool Artigo::operator==(Artigo art) const {
	return (this->nome == art.nome) && (this->tamanho == art.tamanho);
}

ostream& operator<<(ostream& os, Artigo& art) {
	os << art.nome << " - " << art.tamanho << " - " << art.stock << " unidades.";
	return os;
}