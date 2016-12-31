#pragma once

#include "Piscina.h"


using namespace std;

class Artigo {
private:
	string designacao;
	string tamanho;
	unsigned int stock;

public:

	Artigo(string designation, string size, unsigned int estoque);
	Artigo(string designation, string size);
	bool operator <(Artigo outroartigo);
	bool operator ==(Artigo outroartigo);
	string getDesignacao();
	string getTamanho();
	unsigned int getStock();
	void setStock(unsigned int s);
};


class ArtigoInexistente {
private:
	string designacao;
	string tamanho;

public:
	ArtigoInexistente(string designation, string size) {
		this->designacao = designation;
		this->tamanho = size;
	}
};

class SemStock {
private:
	string designacao;
	string tamanho;

public:
	SemStock(string designation, string size) {
		this->designacao = designation;
		this->tamanho = size;
	}
};

