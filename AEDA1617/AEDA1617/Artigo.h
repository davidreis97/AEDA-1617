#pragma once
#include <string>

/**
* @file   Artigo.h
* @brief  Classe que define um artigo.
*
* Classe que define um artigo e as suas caracteristicas.
*/

using namespace std;

class Artigo {
private:
	string nome;
	int stock;
	string tamanho;
public:
	/**
	* Construtor da classe Artigo, usado para criar um artigo. Processa o tamanho do artigo a partir de uma string.
	* @param nome Indica o nome do artigo.
	* @param stock Indica o stock disponivel do artigo.
	* @param tamanho Indica o tamaho do artigo.
	*/
	Artigo(string nome, int stock, string tamanho);
	/**
	* Permite adicionar/remover stock a um artigo caso haja suficiente.
	* @param stock Stock a adicionar.
	* @return True se tiver sucesso, False se não houver stock suficiente para os artigos pedidos.
	*/
	bool addStock(int stock);
	/**
	* Permite obter o stock de um artigo.
	* @return O stock do artigo.
	*/
	int getStock();
	/**
	* Permite obter o nome de um artigo.
	* @return O nome de um artigo.
	*/
	string getNome();
	/**
	* Permite obter o tamanho de um artigo.
	* @return O tamanho do artigo.
	*/
	string getTamanho();
	/**
	* Um artigo é menor que outro se o seu nome for alfabeticamente mais pequeno. Caso o nome seja o mesmo, um artigo é menor que outro se for de tamanho menor.
	*
	* (Isto faz com que a BST esteja ordenada alfabeticamente e, em caso de nomes iguais, por ordem crescente de tamanho.)
	* @return True se o artigo for menor, False se for maior..
	*/
	bool operator<(Artigo art) const;
	/**
	* Um artigo é igual a outro se o seu nome e o seu tamanho forem iguais.
	* @return True se o artigo for menor, False se for maior.
	*/
	bool operator==(Artigo u) const;
	friend ostream& operator<<(ostream& os, Artigo& art);
};

class TamanhoInvalido {
	string tamanho;
public:
	TamanhoInvalido(string tamanho) :tamanho(tamanho) {}
	string getTamanho() { return this->tamanho; }
};

class ArtigoNaoEncontrado {
	Artigo art;
public:
	ArtigoNaoEncontrado(Artigo art) :art(art) {}
	Artigo getArtigo() { return this->art; }
};