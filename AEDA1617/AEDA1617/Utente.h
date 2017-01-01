#pragma once
#include <string>
#include <vector>
#include "Pessoa.h"
#include "Artigo.h"

/**
* @file   Utente.h
* @brief  Classe que define um utente.
*
* Classe que define um utente e os seus consumos na piscina.
*/

using namespace std;

class Utente : public Pessoa {
private:
	int periodosPorPagar;
	int aulasPorPagar; //Todas estas frequencias estao no passado. Utente nao pode pagar antes de frequentar, paga sempre no fim do mes.
	vector<Artigo> artigosComprados;
public:
	/**
	* Construtor da classe Utente, usado para criar um utente que nunca foi cliente da piscina.
	* @param nome Indica o nome do utente.
	* @param idade Indica a idade do utente.
	*/
	Utente(string nome, unsigned int idade);
	/**
	* Construtor da classe Utente, usado para quando se cria um utente auxiliar, com um ID previamente decidido, sem alterar o ultimoID.
	* @param nome O nome do utente a adicionar.
	* @param idade A idade do utente a adicionar.
	* @param id O id do utente a adicionar.
	*/
	Utente(string nome, unsigned int idade, int id);
	/**
	* Permite verificar a igualdade entre dois utentes atraves do seu ID.
	* @return Verdadeiro caso sejam iguais, falso caso não sejam.
	*/
	bool operator==(Utente u) const;
	/**
	* Com base no custo atual de cada aula e cada periodo livre, devolve o valor que o utente deve pagar.
	* @param precoAula Indica o preco de cada aula.
	* @param precoPeriodo Indica o preco de cada periodo.
	* @return O valor que o utente deve pagar.
	*/
	float valorPagamento(float precoAula, float precoPeriodo);
	/**
	* Adiciona ao valor atual de periodos/aulas por pagar.
	* @param aulas Indica quantas aulas se deve incrementar.
	* @param periodos Indica quantos periodos se deve incrementar.
	*/
	void setRelPeriodosPorPagar(int aulas, int periodos);
	/**
	* Define o valor de periodos/aulas por pagar, sem ter em consideracao os valores ja existentes.
	* @param aulas Indica quantas aulas o utente deve pagar.
	* @param periodos Indica quantos periodos o utente deve pagar.
	*/
	void setAbsPeriodosPorPagar(int aulas, int periodos);
	/**
	* Permite obter o numero de periodos que o utente tem por pagar
	* @return O numero de periodos que o utente tem por pagar
	*/
	int getPeriodosPorPagar();
	/**
	* Permite obter o numero de aulas que o utente tem por pagar
	* @return O numero de aulas que o utente tem por pagar
	*/
	int getAulasPorPagar();
	/**
	* Adiciona um artigo que o utente tenha comprado ao vetor respetivo.
	* @param artigo O artigo que o utente comprou.
	*/
	void addArtigo(Artigo artigo);
	/**
	* Imprime uma lista de todos os artigos que o utente comprou.
	*/
	void printArtigos();
	/**
	* Obtem uma copia do vetor de artigos que o cliente comprou.
	* @return O vetor de artigos que o cliente comprou.
	*/
	vector<Artigo> getArtigos();

};