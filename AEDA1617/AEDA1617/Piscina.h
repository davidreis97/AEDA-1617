#pragma once
#include "Utente.h"
#include "Professor.h"
#include "Data.h"
#include "InfoPiscina.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <unordered_set>
#include "BST.h"

/**
* @file   Piscina.h
* @brief  Classe que define uma piscina.
*
* Classe que define uma piscina, contendo os seus utentes, professores e todos os dias de funcionamento. É a classe central de todo o programa.
*/

using namespace std;

struct funcUtente {
	bool operator() (const Utente &u1, const Utente &u2) const {
		return u1.getId() == u2.getId();
	}
	int operator() (const Utente &u) const {
		return u.getId();
	}
};

typedef unordered_set<Utente, funcUtente, funcUtente> tabDisp;

class Piscina {
private:
	vector<Utente> utentes;
	tabDisp utentesInativos;
	vector<Professor> professores;
	vector<Data> horario;
	const unsigned int periodoDia;
	float precoAula;
	float precoPeriodo;
	const unsigned int nMaxUtentes;
	list<string> modalidades;
	priority_queue<InfoPiscina> piscinas_viz;
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
	void marcarUtente(int id, bool isAula, int periodoInicial, int periodoFinal, Data data, string modalidade);
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
	* @param modalidade Modalidade leccionada na aula
	* @return True em caso de sucesso, False em caso de falha.
	*/
	bool newAula(Data data, int periodo, string modalidade);
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
	
	//LOJA
	BST<Artigo> getArtigos();

	BST<Artigo> getArtigos();

	bool addStock(string designation, string size, unsigned int amount);

	bool sellProduct(string designation, string size);

	bool exportStock(string x);
	
	//MODALIDADES

	list<string> getModalidades();

	bool isModalidade(string m);

	bool addModalidade(string m);

	bool removeModalidade(string m);

	InfoPiscina piscinaMaisPerto(string m);

	priority_queue<InfoPiscina> getPiscinas_Viz();

	bool addInfoPiscina(InfoPiscina infoP);

	//UTENTES INATIVOS
	/**
	* Permite gerar a tabela de dispersao de utentes inativos.
	* @param dataAtual A data atual.
	*/	
	void gerarUtentesInativos(Data dataAtual);
	/**
	* Permite alterar a idade de um utente a partir do seu id.
	* @param idade A idade do utente.
	* @param id O id do utente a alterar.
	*/
	void changeIdadeUtente(unsigned int idade, int id);
	/**
	* Imprime uma lista de todos os utentes inativos.
	*/
	void printUtentesInativos();
	/**
	* Imprime o estado de atividade de um utente a partir do seu id.
	* @param id O id do utente.
	*/
	void printAtividadeUtente(int id);
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
