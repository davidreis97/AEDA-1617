#pragma once
#include <ostream>
#include <vector>
#include "Aula.h"

/**
* @file   Data.h
* @brief  Classe que define uma data.
*
* Classe que define uma data, contendo informacao sobre todos os periodos e aulas existentes nesse dia.
*/

using namespace std;

class Data {
private:
	unsigned short dia;
	unsigned short mes;
	unsigned short ano;
	vector<Periodo> periodos;
	vector<Aula> aulas;
public:
	/**
	* Construtor da classe Data, usado para quando se cria uma nova data.
	* @param dia1 O dia da data que se pretende criar.
	* @param mes1 O mes da data que se pretende criar.
	* @param ano1 O ano da data que se pretende criar.
	*/
	Data(unsigned short dia1, unsigned short mes1, unsigned short ano1);
	/**
	* Operador que permite imprimir com sintaxe "user-friendly" a informacao sobre uma determinada data.
	* @return ostream com a informacao desejada.
	*/
	friend ostream & operator<<(ostream &os, Data& data);
	/**
	* Operador que permite determinar se uma data é menor que a outra.
	* @return True caso a "otherdata" seja maior ou igual, False caso contrario.
	*/
	bool operator<(Data otherdata);
	/**
	* Operador que permite determinar a diferenca entre duas datas.
	* @return A diferenca entre duas datas.
	*/
	int operator-(Data otherdata);
	/**
	* Operador que permite determinar se duas datas sao iguais.
	* @return True caso a "otherdata" seja igual, False caso contrario.
	*/
	bool operator==(Data otherdata);
	/**
	* Permite obter o dia de uma data.
	* @return O dia da data.
	*/
	unsigned short getDia();
	/**
	* Permite obter o mes de uma data.
	* @return O mes da data.
	*/
	unsigned short getMes();
	/**
	* Permite obter o ano de uma data.
	* @return O ano da data.
	*/
	unsigned short getAno();
	/**
	* Permite obter o vetor que contem todos os periodos de uma data.
	* @return O vetor de periodos da data.
	*/
	vector<Periodo> *getPeriodos();
	/**
	* Permite obter o vetor que contem todas as aulas de uma data.
	* @return O vetor de aulas da data.
	*/
	vector<Aula> *getAulas();
	/**
	* Permite adicionar um periodo a uma data.
	* @param i O indice do periodo a adicionar.
	*/
	void addPeriodo(int i);
	/**
	* Permite adicionar uma aula a uma data.
	* @param i O indice do periodo a adicionar.
	* @param prof O vetor do professor a adicionar.
	* @param modalidade A modalidade que se pretende adicionar.
	*/
	void addAula(int i, Professor prof, string modalidade);
	/**
	* Permite obter a aula que decorre num determinado periodo.
	* @param periodo O periodo do qual se pretende obter a aula.
	* @return Um apontador para a aula que decorre no periodo pedido.
	*/
	Aula *getAula(int periodo);
	/**
	* Permite obter o periodo que decorre num determinado periodo.
	* @param periodo O periodo do qual se pretende obter a periodo.
	* @return Um apontador para o periodo que decorre no periodo pedido.
	*/
	Periodo *getPeriodo(int periodo);
};

class DataInvalida {
private:
	Data *data;
public:
	Data getData();
	/**
	* Construtor da classe-excepcao DataInvalida, usado para quando se tenta construir uma data que não é valida.
	* @param data A data invalida.
	*/
	DataInvalida(Data* data);
};

class DataNaoEncontrada {
private:
	Data *data;
public:
	Data getData();
	/**
	* Construtor da classe-excepcao DataNaoEncontrada, usado para quando se tenta procurar uma data inexistente.
	* @param data A data inexistente.
	*/
	DataNaoEncontrada(Data* data);
};
