// AEDA-1617.cpp : Defines the entry point for the console application.
//
#include "AEDA-1617.h"


using namespace std;

int main()
{
	menuInicial();
}

void menuInicial() {
	cout << "/***********************/" << endl;
	cout << "1- Criar Piscina" << endl;
	cout << "2- Sair" << endl;
	cout << "/***********************/" << endl;
	int escolha; cin >> escolha;
	switch (escolha) {
	case 1:
	{
		unsigned int periodos, nMax;
		float precoA, precoP;
		cout << "Indique o numero de periodos em que a piscina esta aberta por dia (cada periodo dura meia hora)" << endl;
		cin >> periodos;
		cout << "Indique o custo de cada periodo de Aula" << endl;
		cin >> precoA;
		cout << "Indique o custo de cada periodo livre" << endl;
		cin >> precoP;
		cout << "Indique a capacidade maxima da piscina" << endl;
		cin >> nMax;
		Piscina p(periodos, precoA, precoP, nMax);
		menuPiscina(&p); //Passado como apontador para evitar a duplicação de objetos
		break;
	}
	case 2:
		break;
	default:
		cout << "Escolha invalida" << endl;
		menuInicial();
	}
}

void menuPiscina(Piscina *p) {
	cout << "/***********************/" << endl;
	cout << "1- Utentes" << endl;
	cout << "2- Professores" << endl;
	cout << "3- Horario" << endl;
	cout << "4- Marcacoes" << endl;
	cout << "5- Sair" << endl;
	cout << "/***********************/" << endl;
	int escolha; cin >> escolha;
	switch (escolha) {
	case 1:
		menuUtentes(p);
		break;
	case 2:
		menuProfessores(p);
		break;
	case 3:
		menuHorario(p);
		break;
	case 4:
		menuMarcacoes(p);
		break;
	case 5:
		break;
	default:
		cout << "Escolha invalida" << endl;
		menuPiscina(p);
	}
}

void menuUtentes(Piscina *p) {
	cout << "/***********************/" << endl;
	cout << "1- Novo Utente" << endl;
	cout << "2- Apagar Utente" << endl;
	cout << "3- Consultar Utente" << endl;
	cout << "4- Exportar Utentes" << endl;
	cout << "5- Importar Utentes" << endl;
	cout << "6- Menu Anterior" << endl;
	cout << "/***********************/" << endl;
	int escolha; cin >> escolha;
	switch (escolha) {
	case 1:
	{
		string nome;
		int idade;
		cout << "Indique o nome do utente" << endl;
		cin >> nome;
		cout << "Indique a idade do utente" << endl;
		cin >> idade;
		Utente u(nome, idade);
		(*p).addUtente(u); //Esta função da classe piscina assegura que o utente que se pretende adicionar é adicionado no vetor certo, e nao numa copia. Por esse motivo, deve-se usar este metodo e nao um push_back para inserir objetos neste vetor. Existem funcoes semelhantes para outros vetores do programa.
		menuUtentes(p); //Importante incluir
		break;
	}
	case 2:
		int id;
		cout << "Indique o id do utente" << endl;
		cin >> id;
		(*p).removeUtente(id);
		menuUtentes(p);
		break;
	case 3:
		int id;
		cout << "Indique o id do utente" << endl;
		cin >> id;
		(*p).printFrequenciaUtente(id);
		menuUtentes(p);
		break;
	case 4:
		string x;
		cout << "Introduza o nome do ficheiro de utentes a usar (com .txt no fim) \n";
		cin >> x;

		break;
	case 5:
		//Nesta funcao deve haver leitura de ficheiros
		break;
	case 6:
		menuPiscina(p);
		break;
	default:
		cout << "Escolha invalida" << endl;
		menuUtentes(p);
	}
}

void menuProfessores(Piscina *p) {
	//TODO
}

void menuHorario(Piscina *p) {
	//TODO
}

void menuMarcacoes(Piscina *p) {
	//TODO
}