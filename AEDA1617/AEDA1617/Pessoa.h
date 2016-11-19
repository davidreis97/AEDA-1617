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
	/**
	* Construtor da classe Pessoa, usado para quando se importa uma pessoa de um ficheiro.
	* @param nome O nome do cliente a adicionar.
	* @param idade A idade do cliente a adicionar.
	* @param id O id do cliente a adicionar.
	*/
	Pessoa(string nome, unsigned int idade,int id);
};