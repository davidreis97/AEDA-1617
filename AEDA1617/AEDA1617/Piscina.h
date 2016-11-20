#pragma once
#include "Utente.h"
#include "Professor.h"
#include "Data.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

/**
* @file   Piscina.h
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
	* Permite obter o numero de periodos por dia.
	* @return Numero de periodos por dia.
	*/
	const unsigned int getPeriodoDia();
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
	* @param data Data onde se pretende consultar ocupacao.
	* @param periodo Periodo onde se pretende consultar ocupacao.
	* @return Numero de utentes dentro da piscina.
	*/
	int getNumUtentesAtuais(int periodo, Data data);
	/**
	* Permite efetuar o pagamento das frequencias de um mes de um utente.
	* @param id ID do cliente ao qual se pretende efetuar uma marcacao.
	* @param mes Mes no qual se pretende efetuar o pagamento.
	* @param ano Ano no qual se pretende efetuar o pagamento.
	*/
	void pagarUtente(int id, int mes, int ano);
	/**
	* Imprime no ecrã os utentes na piscina num determinado periodo de um determinado dia.
	* @param d Data onde se pretende consultar ocupacao.
	* @param periodo Periodo onde se pretende consultar ocupacao.
	*/
	void printOcupacaoPiscina(Data d,int periodo);
	/**
	* Imprime no ecrã todas as frequencias na piscina por um determinado utente.
	* @param id ID do cliente ao qual se pretende efetuar a consulta.
	*/
	void printFrequenciaUtente(int id);
	/**
	* Imprime no ecrã todas as frequencias na piscina por todos os utentes da piscina.
	*/
	void printFrequenciaUtentes();
	/**
	* Imprime no ecrã todas as aulas lecionadas por um determinado professor.
	* @param id ID do professor ao qual se pretende efetuar a consulta.
	*/
	void printProfessor(int id);
	/**
	* Imprime no ecrã todos os utentes que frequentaram a piscina em todos os periodos de um determinado dia.
	* @param data Data onde se pretende consultar ocupacao.
	*/
	void printDia(Data data);
	/**
	* Cria uma nova aula num determinado periodo de um determinado dia. Aloca um professor para essa aula, tendo em conta qual dos professores está mais livre.
	* @param data Data onde se pretende efetuar marcacao.
	* @param periodo Periodo onde se pretende efetuar marcacao.
	* @return True em caso de sucesso, False em caso de falha.
	*/
	bool newAula(Data data, int periodo);
	/**
	* Imprime no ecrã todas as aulas lecionadas por todos os professores da piscina.
	*/
	void printProfessores();
	/**
	* Remove um utente.
	* @param id ID do utente a remover.
	* @return True em caso de sucesso, False em caso de falha.
	*/
	bool removeUtente(int id);
	/**
	* Remove um professor, distribuindo todas as suas aulas uniformemente pelo resto dos professores.
	* @param id ID do professor a remover.
	* @return True em caso de sucesso, False em caso de falha.
	*/
	bool removeProfessor(int id);
	/**
	* Permite importar uma lista de clientes de um ficheiro.
	* @param x Nome do ficheiro a importar.
	* @return True em caso de sucesso, False em caso de falha.
	*/
	bool importUtentes(string x);
	/**
	* Permite exportar uma lista de clientes de um ficheiro.
	* @param x Nome do ficheiro a exportar.
	* @return True em caso de sucesso, False em caso de falha.
	*/
	bool exportUtentes(string x);
	/**
	* Permite importar uma lista de professores de um ficheiro.
	* @param x Nome do ficheiro a importar.
	* @return True em caso de sucesso, False em caso de falha.
	*/
	bool importProfessores(string x);
	/**
	* Permite exportar uma lista de professores de um ficheiro.
	* @param x Nome do ficheiro a exportar.
	* @return True em caso de sucesso, False em caso de falha.
	*/
	bool exportProfessores(string x);
};

class PiscinaCheia {
	int nMaxUtentes;
public:
	/**
	* Construtor da classe-excepcao PiscinaCheia, usado para quando nao e adicionar mais clientes num determinado periodo por estar demasiada gente na piscina.
	* @param nMaxUtentes O numero maximo de utentes permitidos na piscina.
	*/
	PiscinaCheia(int nMaxUtentes);
	/**
	* Construtor da classe-excepcao PiscinaCheia, usado para quando nao e adicionar mais clientes num determinado periodo por estar demasiada gente na piscina.
	* @param nMaxUtentes O numero maximo de utentes permitidos na piscina.
	*/
	int getNMaxUtentes();
};
