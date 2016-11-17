#pragma once
#include <string>
/**
* @file   Pessoa.h
* @date   November, 2016
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
	int getId();
	string getNome();
	Pessoa(string nome, unsigned int idade);
	Pessoa(string nome, unsigned int idade,int id);
};