#pragma once
#include "Utente.h"
#include "Professor.h"
#include "Data.h"
#include <algorithm>
#include <iostream>

/**
* @file   Piscina.h
* @date   November, 2016
* @brief  Classe que define uma piscina.
*
* Classe que define uma piscina, contendo os seus utentes, professores e todos os dias de funcionamento. É a classe central de todo o programa.
*/

using namespace std;
class Piscina {
private:
	vector<Utente> utentes;
	vector<Professor> professores;
	vector<Data> horario;
	const unsigned int periodoDia;
	float precoAula;
	float precoPeriodo;
	const unsigned int nMaxUtentes;
public:
	/**
	* Construtor da classe Piscina, usado para criar uma piscina.
	* @param periodos Indica o numero de periodos que ha por dia.
	* @param precoA Indica o preco de uma aula.
	* @param precoP Indica o preco de um periodo.
	* @param nMax Inica o numero maximo de utentes num determinado periodo na piscina.
	*/
	Piscina(unsigned int periodos, float precoA, float precoP, unsigned int nMax);
	/**
	* Permite obter uma copia do vetor utentes.
	* @return Copia do vetor utentes.
	*/
	vector<Utente> getUtentes();
	/**
	* Permite obter uma copia do vetor professores.
	* @return Copia do vetor professores.
	*/
	vector<Professor> getProfessores();
	/**
	* Permite adicionar um utente ao vetor utentes, verificando se este ja existe ou nao.
	* @param u Utente a adicionar.
	* @return True caso o utente tenha sido adicionado, falso caso ja tenha sido encontrado um utente igual.
	*/
	bool addUtente(Utente u);
	/**
	* Permite adicionar um professor ao vetor professores, verificando se este ja existe ou nao.
	* @param p Professor a adicionar.
	* @return True caso o utente tenha sido adicionado, falso caso ja tenha sido encontrado um professor igual.
	*/
	bool addProfessor(Professor p);
	/**
	* Permite adicionar uma data ao vetor datas, verificando se esta ja existe ou nao, inicializando também todos os periodos desse dia.
	* @param d Data a adicionar.
	* @return True caso a data tenha sido adicionada, falso caso ja tenha sido encontrado uma data igual.
	*/
	bool addData(Data d);
	/**
	* Permite obter o numero de utentes em aula, num determinado periodo de um determinado dia.
	* @param d Data onde se pretende consultar ocupacao.
	* @param p Periodo onde se pretende consultar ocupacao.
	* @return Numero de utentes em aula
	*/
	int	 getNumUtentesAula(int periodo, Data data);
	/**
	* Permite marcar a frequencia de um utente, quer seja numa aula ou num periodo livre, tendo em conta a ocupacao da piscina nos periodos pedidos.
	* @param id ID do cliente ao qual se pretende efetuar uma marcacao.
	* @param isAula True se pretender marcar uma aula, false se pretender marcar um periodo livre.
	* @param periodoInicial Primeiro periodo em que se pretende marcar.
	* @param periodoFinal Ultimo periodo em que se pretende marcar.
	* @param data Data em que se pretende marcar.
	*/
	void marcarUtente(int id, bool isAula, int periodoInicial, int periodoFinal, Data data);
	/**
	* Permite obter o numero de utentes dentro da piscina, num determinado periodo de um determinado dia.
	* @param d Data onde se pretende consultar ocupacao.
	* @param p Periodo onde se pretende consultar ocupacao.
	* @return Numero de utentes dentro da piscina.
	*/
	int  getNumUtentesAtuais(int periodo, Data data);
	/**
	* Permite efetuar o pagamento das frequencias de um mes de um utente.
	* @param id ID do cliente ao qual se pretende efetuar uma marcacao.
	* @param isAula True se pretender marcar uma aula, false se pretender marcar um periodo livre.
	* @param periodoInicial Primeiro periodo em que se pretende marcar.
	* @param periodoFinal Ultimo periodo em que se pretende marcar.
	* @param data Data em que se pretende marcar.
	*/
	void pagarUtente(int id, int mes);
	void printOcupacaoPiscina(Data d,int periodo);
	void printFrequenciaUtente(int id);
	void printProfessor(int id);
	void printDia(Data data);
	bool newAula(Data data, int periodo);
	void printProfessores();
	bool removeUtente(int id);
	bool removeProfessor(int id);
};

class PiscinaCheia {
	int nMaxUtentes;
public:
	PiscinaCheia(int nMaxUtentes);
	int getNMaxUtentes();
};
