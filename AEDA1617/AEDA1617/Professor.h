#pragma once
#include "Pessoa.h"

/**
* @file   Professor.h
* @brief  Classe que define um professor.
*
* Classe que define um professor e as aulas que este leciona.
*/

using namespace std;
class Professor :public Pessoa{
	int aulas;
public:
	/**
	* Construtor da classe Professor, usado para criar um professor novo.
	* @param nome Indica o nome do professor.
	* @param idade Indica a idade do professor.
	*/
	Professor(string nome, unsigned int idade);
	/**
	* Construtor da classe Professor, usado para criar um professor importado de um ficheiro.
	* @param nome Indica o nome do professor.
	* @param idade Indica a idade do professor.
	* @param id Indica o ID do professor.
	* @param aulas Indica as aulas dadas pelo professor.
	*/
	Professor(string nome, unsigned int idade, int id, int aulas);
	/**
	* Permite verificar a igualdade entre dois professores atraves do seu ID.
	* @return Verdadeiro caso sejam iguais, falso caso não sejam.
	*/
	bool Professor::operator==(Professor u);
	/**
	* Permite obter o numero de aulas que o professor ja leccionou.
	* @return O numero de aulas que o professor ja leccionou.
	*/
	int getNumAulas();
	/**
	* Incrementa ao valor atual de periodos/aulas leccionadas.
	* @param aulas Indica quantas aulas se deve incrementar.
	*/
	void setNumAulas(int aulas);
};

