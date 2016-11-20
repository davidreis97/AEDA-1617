#pragma once
#include "Utente.h"
#include "Professor.h"

/**
* @file   Aula.h
* @brief  Classes que definem uma aula e um periodo.
*
* Classes que definem uma aula e um periodo, cada um guardando um vetor de utentes que frequentam esse periodo, sendo que no caso da aula guarda tambem o professor responsavel por leccionar essa aula.
*/

using namespace std;

class Periodo {
	vector<Utente> utentes;
	int periodo;
public:
	/**
	* Construtor da classe Periodo, usado para criar um periodo livre na piscina.
	* @param periodo Indica o indice do periodo a criar.
	*/
	Periodo(int periodo);
	/**
	* Permite obter o indice do periodo.
	* @return O indice do periodo a criar.
	*/
	int getPeriodo();
	/**
	* Permite obter um apontador para o vetor utentes.
	* @return Um apontador para o vetor utentes.
	*/
	vector<Utente> *getUtentes();
	/**
	* Permite obter o numero de utentes num periodo.
	* @return O numero de utentes num periodo.
	*/
	int getNumUtentes();
	/**
	* Permite adicionar um utente ao vetor de utentes.
	* @param utente O utente a adicionar.
	*/
	void addUtente(Utente utente);
};

class Aula : public Periodo{
	Professor professor;
public:
	/**
	* Construtor da classe Aula, usado para criar uma aula na piscina.
	* @param periodo Indica o indice do periodo da aula a criar.
	* @param professor Indica o professor atribuido à aula a criar.
	*/
	Aula(Professor professor, int periodo);
	/**
	* Permite obter o professor responsavel pela aula.
	* @return O professor responsavel pela aula.
	*/
	Professor getProfessor();
	/**
	* Permite definir o professor responsavel pela aula.
	* @param professor O professor responsavel pela aula.
	*/
	void setProfessor(Professor professor);
};