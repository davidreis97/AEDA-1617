﻿// AEDA-1617.cpp : Defines the entry point for the console application.
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
		menuPiscina(&p); //Passado sempre como apontador para evitar a duplica��o desnecess�ria de objetos
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
	cout << "5- Loja" << endl;
	cout << "6- Modalidades" << endl;
	cout << "7- Utentes Inativos" << endl;
	cout << "8- Informacao Outras Piscinas" << endl;
	cout << "9- Sair" << endl;
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
		menuLoja(p);
		break;
	case 6:
		menuModalidades(p);
		break;
	case 7:
		menuUtentesInativos(p);
		break;
	case 8:
		menuInfoPiscina(p);
	case 9:
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
	cout << "4- Consultar todos os Utentes" << endl;
	cout << "5- Efetuar Pagamento" << endl;
	cout << "6- Exportar Utentes" << endl;
	cout << "7- Importar Utentes" << endl;
	cout << "8- Menu Anterior" << endl;
	cout << "/***********************/" << endl;
	int escolha; cin >> escolha;
	switch (escolha) {
	case 1:
	{
		string nome;
		int idade;
		cout << "Indique o nome do utente" << endl;
		cin.ignore();
		getline(cin, nome);
		cout << "Indique a idade do utente" << endl;
		cin >> idade;
		Utente u(nome, idade);
		(*p).addUtente(u); //Esta fun��o da classe piscina assegura que o utente que se pretende adicionar � adicionado no vetor certo, e nao numa copia. Por esse motivo, deve-se usar este metodo e nao um push_back para inserir objetos neste vetor. Existem funcoes semelhantes para outros vetores do programa.
		menuUtentes(p); //Importante incluir
		break;
	}
	case 2:
	{
		int id;
		cout << "Indique o id do utente" << endl;
		cin >> id;
		(*p).removeUtente(id);
		menuUtentes(p);
		break;
	}
	case 3:
	{
		int id;
		cout << "Indique o id do utente" << endl;
		cin >> id;
		try {
			(*p).printFrequenciaUtente(id);
		}
		catch (PessoaNaoEncontrada pne) {
			cout << "Erro! Nao foi encontrada a pessoa com ID " << pne.getId() << " nos nossos registos." << endl;
		}

		menuUtentes(p);
		break;
	}
	case 4:
	{
		(*p).printFrequenciaUtentes();
		menuUtentes(p);
		break;
	}
	case 5:
	{
		int id, mes, ano;
		cout << "Indique o id do utente" << endl;
		cin >> id;
		cout << "Indique o mes que pretende pagar" << endl;
		cin >> mes;
		cout << "Indique o ano do mes que pretende pagar" << endl;
		cin >> ano;
		try {
			(*p).pagarUtente(id, mes, ano);
		}
		catch (PessoaNaoEncontrada pne) {
			cout << "Erro! Nao foi encontrada a pessoa com ID " << pne.getId() << " nos nossos registos." << endl;
		}
		menuUtentes(p);
		break;
	}
	case 6:
	{
		string x;
		cout << "Introduza o nome do ficheiro de utentes a usar \n";
		cin >> x;
		(*p).exportUtentes(x);
		menuUtentes(p);
		break;
	}
	case 7:
	{
		string x;
		cout << "Introduza o nome do ficheiro de utentes a usar \n";
		cin >> x;
		(*p).importUtentes(x);
		menuUtentes(p);
		break;
	}
	case 8:
	{
		menuPiscina(p);
		break;
	}
	default:
		cout << "Escolha invalida" << endl;
		menuUtentes(p);
	}
}

void menuProfessores(Piscina *p) {
	cout << "/***********************/" << endl;
	cout << "1- Novo Professor" << endl;
	cout << "2- Apagar Professor" << endl;
	cout << "3- Consultar Professor" << endl;
	cout << "4- Consultar todos os Professores" << endl;
	cout << "5- Exportar Professores" << endl;
	cout << "6- Importar Professores" << endl;
	cout << "7- Menu Anterior" << endl;
	cout << "/***********************/" << endl;
	int escolha; cin >> escolha;
	switch (escolha) {
	case 1:
	{
		string nome;
		int idade;
		cout << "Indique o nome do professor" << endl;
		cin.ignore();
		getline(cin, nome);
		cout << "Indique a idade do professor" << endl;
		cin >> idade;
		Professor prof(nome, idade);
		(*p).addProfessor(prof); //Esta funcao da classe piscina assegura que o professor que se pretende adicionar � adicionado no vetor certo, e nao numa copia. Por esse motivo, deve-se usar este metodo e nao um push_back para inserir objetos neste vetor. Existem funcoes semelhantes para outros vetores do programa.
		menuProfessores(p); //Importante incluir
		break;
	}
	case 2:
	{
		int id;
		cout << "Indique o id do professor" << endl;
		cin >> id;
		(*p).removeProfessor(id);
		menuProfessores(p);
		break;
	}
	case 3:
	{
		int id;
		cout << "Indique o id do professor" << endl;
		cin >> id;
		try {
			(*p).printProfessor(id);
		}
		catch (PessoaNaoEncontrada pne) {
			cout << "Erro! Nao foi encontrada a pessoa com ID " << pne.getId() << " nos nossos registos." << endl;
		}
		menuProfessores(p);
		break;
	}
	case 4:
	{
		(*p).printProfessores();
		menuProfessores(p);
		break;
	}
	case 5:
	{
		string x;
		cout << "Introduza o nome do ficheiro de professores a usar \n";
		cin >> x;
		(*p).exportProfessores(x);
		menuProfessores(p);
		break;
	}
	case 6:
	{
		string x;
		cout << "Introduza o nome do ficheiro de professores a usar \n";
		cin >> x;
		(*p).importProfessores(x);
		menuProfessores(p);
		break;
	}
	case 7:
	{
		menuPiscina(p);
		break;
	}
	default:
		cout << "Escolha invalida" << endl;
		menuProfessores(p);
	}
}

void menuHorario(Piscina *p) {
	cout << "/***********************/" << endl;
	cout << "1- Consultar Periodo" << endl;
	cout << "2- Consultar Dia" << endl;
	cout << "3- Menu Anterior" << endl;
	cout << "/***********************/" << endl;
	int escolha; cin >> escolha;
	switch (escolha) {
	case 1:
	{
		int dia, mes, ano, periodo;
		cout << "Indique o dia em que pretende efetuar a consulta" << endl;
		cin >> dia;
		cout << "Indique o mes em que pretende efetuar a consulta" << endl;
		cin >> mes;
		cout << "Indique o ano em que pretende efetuar a consulta" << endl;
		cin >> ano;
		cout << "Indique o periodo em que pretende efetuar a consulta" << endl;
		cin >> periodo;
		if (periodo > (*p).getPeriodoDia() || periodo < 0) {
			cout << "Erro! Periodo invalido!" << endl;
		}
		else {
			try {
				Data d(dia, mes, ano);
				(*p).printOcupacaoPiscina(d, periodo);
			}
			catch (DataInvalida di) {
				cout << "Erro! A data " << di.getData() << " nao e valida." << endl;
			}
			catch (DataNaoEncontrada dne) {
				cout << "Erro! Nao foi encontrada a data " << dne.getData() << " nos nossos registos." << endl;
			}
		}
		menuHorario(p);
		break;
	}
	case 2:
	{
		int dia, mes, ano;
		cout << "Indique o dia em que pretende efetuar a consulta" << endl;
		cin >> dia;
		cout << "Indique o mes em que pretende efetuar a consulta" << endl;
		cin >> mes;
		cout << "Indique o ano em que pretende efetuar a consulta" << endl;
		cin >> ano;
		try {
			Data d(dia, mes, ano);
			(*p).printDia(d);
		}
		catch (DataInvalida di) {
			cout << "Erro! A data " << di.getData() << " nao e valida." << endl;
		}
		menuHorario(p);
		break;
	}
	case 3:
		menuPiscina(p);
		break;
	default:
		cout << "Escolha invalida" << endl;
		menuHorario(p);
	}
}

void menuMarcacoes(Piscina *p) {
	cout << "/***********************/" << endl;
	cout << "1- Marcar Aula" << endl;
	cout << "2- Marcar Periodo" << endl;
	cout << "3- Nova Aula" << endl;
	cout << "4- Voltar Atras" << endl;
	cout << "/***********************/" << endl;
	int escolha; cin >> escolha;
	switch (escolha) {
	case 1:
	{
		int dia, mes, ano, periodo, id;
		string modalidade;
		cout << "Indique a modalidade que quer efetuar a marcacao" << endl;
		cin.ignore();
		getline(cin, modalidade);
		if (p->isModalidade(modalidade)) {
			cout << "Indique o ID do cliente que quer efetuar a marcacao" << endl;
			cin >> id;
			cout << "Indique o dia em que pretende efetuar a marcacao" << endl;
			cin >> dia;
			cout << "Indique o mes em que pretende efetuar a marcacao" << endl;
			cin >> mes;
			cout << "Indique o ano em que pretende efetuar a marcacao" << endl;
			cin >> ano;
			cout << "Indique o periodo em que pretende efetuar a marcacao (Aula tem sempre duracao de 2 periodos, ou seja, 1 hora)" << endl;
			cin >> periodo;
			if (periodo < 0 || periodo + 1 >(*p).getPeriodoDia()) {
				cout << "Erro! Periodo invalido!" << endl;
			}
			else {
				try {
					Data d(dia, mes, ano);
					(*p).marcarUtente(id, true, periodo, periodo + 1, d);
				}
				catch (PessoaNaoEncontrada pne) {
					cout << "Erro! Nao foi encontrada a pessoa com ID " << pne.getId() << " nos nossos registos." << endl;
				}
				catch (PiscinaCheia pc) {
					cout << "Erro! A lotacao da piscina no periodo pedido excede a lotacao maxima de " << pc.getNMaxUtentes() << " pessoas." << endl;
				}
				catch (DataInvalida di) {
					cout << "Erro! A data " << di.getData() << " nao e valida." << endl;
				}
			}
		}
		else {
			cout << "Modalidade nao disponivel" << endl;
			InfoPiscina infoP("Nome", 1);
			infoP = p->piscinaMaisPerto(modalidade);
			if (infoP.getDistancia() == -1)
				cout << "Nao existe nenhuma piscina nos registos com a modalidade disponivel." << endl;
			else
				cout << "A piscina " << infoP.getNome << " tem a modalidade disonivel e encontra-se a " << infoP.getDistancia() << " unidades de distancia.";
		}
		menuMarcacoes(p);
		break;
	}
	case 2:
	{
		int dia, mes, ano, periodoInicial, periodoFinal, id;
		cout << "Indique o ID do cliente que quer efetuar a marcacao" << endl;
		cin >> id;
		cout << "Indique o dia em que pretende efetuar a marcacao" << endl;
		cin >> dia;
		cout << "Indique o mes em que pretende efetuar a marcacao" << endl;
		cin >> mes;
		cout << "Indique o ano em que pretende efetuar a marcacao" << endl;
		cin >> ano;
		cout << "Indique o periodo inicial em que pretende efetuar a marcacao" << endl;
		cin >> periodoInicial;
		cout << "Indique o periodo final em que pretende efetuar a marcacao" << endl;
		cin >> periodoFinal;
		if (periodoInicial < 0 || periodoFinal >(*p).getPeriodoDia() || periodoFinal < periodoInicial) {
			cout << "Erro! Periodo invalido!" << endl;
		}
		else {
			try {
				Data d(dia, mes, ano);
				(*p).marcarUtente(id, false, periodoInicial, periodoFinal, d);
			}
			catch (PessoaNaoEncontrada pne) {
				cout << "Erro! Nao foi encontrada a pessoa com ID " << pne.getId() << " nos nossos registos." << endl;
			}
			catch (PiscinaCheia pc) {
				cout << "Erro! A lotacao da piscina no periodo pedido excede a lotacao maxima de " << pc.getNMaxUtentes() << " pessoas." << endl;
			}
			catch (DataInvalida di) {
				cout << "Erro! A data " << di.getData() << " nao e valida." << endl;
			}
		}
		menuMarcacoes(p);
		break;
	}
	case 3:
	{
		int dia, mes, ano, periodo;
		string modalidade;
		cout << "Indique o dia em que pretende criar uma nova aula" << endl;
		cin >> dia;
		cout << "Indique o mes em que pretende criar uma nova aula" << endl;
		cin >> mes;
		cout << "Indique o ano em que pretende criar uma nova aula" << endl;
		cin >> ano;
		cout << "Indique o periodo em que pretende uma nova aula" << endl;
		cin >> periodo;
		cout << "Indique a modalidade" << endl;
		cin.ignore();
		getline(cin, modalidade);
		if (p->isModalidade(modalidade)) {
			if (periodo < 0 || periodo + 1 >(*p).getPeriodoDia()) {
				cout << "Erro! Periodo invalido!" << endl;
			}
			else {
				try {
					Data d(dia, mes, ano);
					(*p).newAula(d, periodo, modalidade);
				}
				catch (DataInvalida di) {
					cout << "Erro! A data " << di.getData() << " nao e valida." << endl;
				}
			}
		}
		else {
			cout << "Modalidade nao disponivel nesta piscina" << endl;
		}
		menuMarcacoes(p);
		break;
	}
	case 4:
		menuPiscina(p);
		break;
	default:
		cout << "Escolha invalida" << endl;
		menuMarcacoes(p);
	}
}

void menuLoja(Piscina *p) { //José
	/*TODO*/
}

void menuModalidades(Piscina *p) { //Nuno
	cout << "/***********************/" << endl;
	cout << "1- Imprimir Lista de Modalidades" << endl;
	cout << "2- Adicionar Nova Modalidade" << endl;
	cout << "3- Remover Modalidade" << endl;
	cout << "4- Menu Anterior" << endl;
	cout << "/***********************/" << endl;
	int escolha; cin >> escolha;
	switch (escolha) {
	case 1: {
		list<string> aux;
		aux = p->getModalidades();
		list<string>::iterator it;
		if (aux.empty())
			cout << "Piscina não tem modalidades disponíveis." << endl;
		else {
			cout << "Lista de Modalidades:" << endl;
			for (it = aux.begin(); it != aux.end(); it++) {
				cout << *it << endl;
			}
		}
		menuModalidades(p);
		break;
	}
	case 2: {
		string modalidade;
		cout << "Insira a modalidade: ";
		cin.ignore();
		getline(cin, modalidade);
		if (p->addModalidade(modalidade))
			cout << "Modalidade adicionada com sucesso." << endl;
		else
			cout << "Modalidade ja existente" << endl;
		menuModalidades(p);
		break;
	}
	case 3: {
		string modalidade;
		cout << "Insira a modalidade: ";
		cin.ignore();
		getline(cin, modalidade);
		if (p->removeModalidade(modalidade))
			cout << "Modalidade removida com sucesso." << endl;
		else
			cout << "A modalidade que indicou nao existe nas habilidades disponiveis" << endl;
		menuModalidades(p);
		break;
	}
	case 4: {
		menuPiscina(p);
		break;
	}
	default:
		cout << "Escolha invalida" << endl;
		menuUtentesInativos(p);
	}
}

void menuUtentesInativos(Piscina *p) { //David
	cout << "/***********************/" << endl;
	cout << "1- Imprimir Lista de Utentes Inativos" << endl;
	cout << "2- Alterar Idade de um Utente" << endl;
	cout << "3- Imprimir Atividade de um Utente" << endl;
	cout << "4- Menu Anterior" << endl;
	cout << "/***********************/" << endl;
	int escolha; cin >> escolha;
	switch (escolha) {
	case 1:
	{
		int dia, mes, ano;
		cout << "Indique o dia atual" << endl;
		cin >> dia;
		cout << "Indique o mes atual" << endl;
		cin >> mes;
		cout << "Indique o ano atual" << endl;
		cin >> ano;
		try {
			Data d(dia, mes, ano);
			(*p).gerarUtentesInativos(d);
			(*p).printUtentesInativos();
		}
		catch (DataInvalida di) {
			cout << "Erro! A data " << di.getData() << " nao e valida." << endl;
		}
		menuUtentesInativos(p);
		break;
	}
	case 2:
	{
		int id;
		unsigned int idade;
		cout << "Indique o id do cliente" << endl;
		cin >> id;
		cout << "Indique a idade nova do cliente" << endl;
		cin >> idade;
		try {
			(*p).changeIdadeUtente(idade, id);
		}
		catch (PessoaNaoEncontrada pne) {
			cout << "Erro! Nao foi encontrada a pessoa com ID " << pne.getId() << " nos nossos registos." << endl;
		}
		menuUtentesInativos(p);
		break;
	}
	case 3:
	{
		int id, dia, mes, ano;
		cout << "Indique o id do cliente" << endl;
		cin >> id;
		cout << "Indique o dia atual" << endl;
		cin >> dia;
		cout << "Indique o mes atual" << endl;
		cin >> mes;
		cout << "Indique o ano atual" << endl;
		cin >> ano;
		try {
			Data d(dia, mes, ano);
			(*p).gerarUtentesInativos(d);
			(*p).printAtividadeUtente(id);
		}
		catch (PessoaNaoEncontrada pne) {
			cout << "Erro! Nao foi encontrada a pessoa com ID " << pne.getId() << " nos nossos registos." << endl;
		}
		catch (DataInvalida di) {
			cout << "Erro! A data " << di.getData() << " nao e valida." << endl;
		}
		menuUtentesInativos(p);
		break;
	}
	case 4:
		menuPiscina(p);
		break;
	default:
		cout << "Escolha invalida" << endl;
		menuUtentesInativos(p);
	}
}

void menuInfoPiscina(Piscina *p) {
	cout << "/***********************/" << endl;
	cout << "1- Imprimir Informacao das Piscinas" << endl;
	cout << "2- Adicionar Informacao de Piscina" << endl;
	cout << "3- Menu Anterior" << endl;
	cout << "/***********************/" << endl;
	int escolha; cin >> escolha;
	switch (escolha) {
	case 1: {
		priority_queue<InfoPiscina> aux;
		aux = p->getPiscinas_Viz();
		if (aux.empty())
			cout << "Nao tem informacao." << endl;
		else
			while (!aux.empty()) {
				InfoPiscina infoP("Nome", 1);
				infoP = aux.top();
				cout << "Nome: " << infoP.getNome() << endl;
				cout << "Distancia: " << infoP.getDistancia() << endl;
				cout << "Modalidades:" << endl;
				list<string>::iterator it;
				for (it = infoP.getModalidades().begin(); it != infoP.getModalidades().end(); it++) {
					cout << *it << endl;
				}
			}
		menuInfoPiscina(p);
		break;
	}
	case 2: {
		string nome;
		int distancia = 0;
		cout << "Insira o nome da Piscina: ";
		cin.ignore();
		getline(cin, nome);
		while (distancia <= 0) {
			cout << "Insira a distancia a que se encontra a piscina: ";
			cin >> distancia;
		}
		InfoPiscina infoP(nome, distancia);
		
		string continuar = "y";
		while (continuar == "y") {
			string modalidade;
			cout << "Insira uma modalidade: " << endl;
			cin.ignore();
			getline(cin, modalidade);
			list<string>::iterator it;
			bool ja_inserida = false;
			for (it = infoP.getModalidades().begin(); it != infoP.getModalidades.end(); it++) {
				if (*it == modalidade) {
					ja_inserida = true;
					break;
				}
			}
			if (ja_inserida)
				cout << "Erro: Modalidade ja existente." << endl;
			else {
				infoP.addModalidade(modalidade);
				cout << "Modalidade adicionada com sucesso." << endl;
				string sn;
				while (sn != "y" || sn != "n") {
					cout << "Deseja inserir outra modalidade (y/n): ";
					cin >> sn;
				}
				continuar = sn;
			}

		}
		if (p->addInfoPiscina(infoP))
			cout << "Adicionada informacao com sucesso." << endl;
		else
			cout << "Erro: Informacao de Piscina ja existente. " << endl;

		menuInfoPiscina(p);
		break;
	}
	case 3: {
		menuPiscina(p);
		break;
	}
	default:
		cout << "Escolha invalida" << endl;
		menuInfoPiscina(p);
	}
}