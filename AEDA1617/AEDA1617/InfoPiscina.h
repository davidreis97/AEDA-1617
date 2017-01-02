#pragma once
#include <string>
#include <list>
#include <iostream>

/**
* @file   InfoPiscina.h
* @brief  Classe que armazena informacao de uma piscina vizinha.
*
* Contém o nome da piscina, as modalidades e a distância que se encontra a piscina da principal.
*/

using namespace std;

class InfoPiscina {
private:
	string nome;
	list<string> modalidades;
	int distancia;
public:

	/**
	* Construtor do InfoPiscina
	* @param nome nome da piscina
	* @param distancia distancia a que se encontra da piscina
	*/
	InfoPiscina(string nome, int distancia);

	/**
	* Função que obtem o nome da piscina
	* @return Nome da piscina
	*/
	string getNome();

	/**
	* Função que retorna a lista de modalidades da piscina
	* @return Lista de modalidades da piscina
	*/
	list<string> getModalidades();

	/**
	* Função que retorna a que distância se encontra a piscina
	* @return Distância
	*/
	int getDistancia();

	/**
	* Função que adiciona adiciona uma modalidade à lista de modalidades da piscina
	* @param m nome da modalidade
	* @return true se foi adicionada com sucesso
	* @return false se já existir a modalidade m na lista
	*/
	bool addModalidade(string m);

	/**
	* Função que imprime a lista de modalidades no ecrã
	*/
	void printModalidades();

	/**
	* Overload do operador =.
	* @param p InfoPiscina que pretendemos copiar
	* @return InfoPiscina com o mesmo nome, modalidades e distancia de p
	*/
	InfoPiscina & operator=(const InfoPiscina & p);

	/**
	* Overload do operador ==.
	* @param p InfoPiscina que pretendemos comparar
	* @return true se o nome de p for igual ao da piscina
	* @return false caso contrário
	*/
	bool operator==(const InfoPiscina & p) const;

	/**
	* Overload do operador<.
	* @param p InfoPiscina que pretendemos comparar
	* @return true se a distancia da piscina for maior que a distancia de p
	* @return false caso contrário
	*/
	bool operator<(const InfoPiscina & p) const;
};