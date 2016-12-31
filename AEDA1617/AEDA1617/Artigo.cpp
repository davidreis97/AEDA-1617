#include "Artigo.h"


Artigo::Artigo(string designation, string size, unsigned int estoque) {
	this->designacao = designation;
	this->tamanho = size;
	this->stock = estoque;
	//fazer condicao if para verificar se esta tudo conforme e caso nao lançar excecoes
}

Artigo::Artigo(string designation, string size) {
	this->designacao = designation;
	this->tamanho = size;
	stock = 0;
}

bool Artigo::operator<(Artigo outroartigo) {
	if (this->designacao < outroartigo.designacao)
		return true;
	else if (this->designacao == outroartigo.designacao)
	{
		if (this->tamanho == "S")
			return true;
		else if (this->tamanho == "M")
			if (outroartigo.tamanho == "S")
				return false;
			else return true;
		else if (this->tamanho == "L")
			if (outroartigo.tamanho == "S" || outroartigo.tamanho == "M")
				return false;
			else return true;
		else if (this->tamanho == "XL")
			return false;
	}
	else return false;
}

bool Artigo::operator==(Artigo outroartigo) {
	if (this->designacao == outroartigo.designacao && this->tamanho == outroartigo.tamanho)
		return true;
	else return false;
}

unsigned int Artigo::getStock()
{
	return this->stock;
}

void Artigo::setStock(unsigned int s) {
	this->stock = s;
}


