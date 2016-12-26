#pragma once
#include <string>
/**
* @file   Pessoa.h
* @brief  Classe que define uma pessoa.
*
* Classe que define uma pessoa, nunca é instanciada.
*/


using namespace std;

class Pessoa {
private:
	string nome;
	int id;
	unsigned int idade;
public:
	static int ultimoId;
	/**
	* Permite obter o id de uma pessoa.
	* @return O id da pessoa.
	*/
	int getId() const;
	/**
	* Permite obter a idade de uma pessoa.
	* @return A idade da pessoa.
	*/
	int getIdade();
	/**
	* Permite definir a idade de uma pessoa.
	* @param i A idade da pessoa.
	*/
	void setIdade(unsigned int i);
	/**
	* Permite obter o nome de uma pessoa.
	* @return O nome da pessoa.
	*/
	string getNome();
	/**
	* Construtor da classe Pessoa, usado para quando se cria uma pessoa nova.
	* @param nome O nome da pessoa a adicionar.
	* @param idade A idade da pessoa a adicionar.
	*/
	Pessoa(string nome, unsigned int idade);
};

class PessoaNaoEncontrada {
	int id;
public:
	/**
	* Construtor da classe-excepcao UtenteNaoEncontrado, usado para quando nao e possivel encontrar uma pessoa com um determinado ID.
	* @param id O ID da pessoa que nao foi encontrado.
	*/
	PessoaNaoEncontrada(int id);
	int getId();
};