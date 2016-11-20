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
	* Permite obter o id de um cliente.
	* @return O id do cliente.
	*/
	int getId();
	/**
	* Permite obter a idade de um cliente.
	* @return A idade do cliente.
	*/
	int getIdade();
	/**
	* Permite obter o nome de um cliente.
	* @return O nome do cliente.
	*/
	string getNome();
	/**
	* Construtor da classe Pessoa, usado para quando se cria uma pessoa nova.
	* @param nome O nome do cliente a adicionar.
	* @param idade A idade do cliente a adicionar.
	*/
	Pessoa(string nome, unsigned int idade);
};

class PessoaNaoEncontrada {
	int id;
public:
	/**
	* Construtor da classe-excepcao UtenteNaoEncontrado, usado para quando nao e possivel encontrar um cliente com um determinado ID.
	* @param id O ID do cliente que nao foi encontrado.
	*/
	PessoaNaoEncontrada(int id);
	int getId();
};