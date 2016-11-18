// AEDA-1617.cpp : Defines the entry point for the console application.
//
#include "ShowMenu.h"
#include "Utente.h"
#include "Piscina.h"
#include <sstream>
#include <vector>
#include <fstream>
#include <string>


using namespace std;

int main()
{
	Piscina p(16, 2, 1.5, 5);
	Utente u1("Jeremias", 13);
	Utente u2("Jacob", 54);
	Utente u3("Genoveva", 32);
	Utente u4("Mariana", 18);
	Utente u5("David", 19);
	Utente u6("Nuno", 19);
	Utente u7("José", 19);
	p.addUtente(u1);
	p.addUtente(u2);
	p.addUtente(u3);
	p.addUtente(u4);
	p.addUtente(u5);
	p.addUtente(u6);
	p.addUtente(u7);
	Data data(11, 07, 2016);
	Data data1(10, 07, 2016);
	p.marcarUtente(1, 0, 0, 4, data);
	p.marcarUtente(4, 0, 0, 4, data);
	Professor prof("Alfredo", 99);
	Professor prof1("Cabrao", 23);
	Professor prof2("Filho da puta", 23232);
	p.addProfessor(prof);
	p.addProfessor(prof1);
	p.addProfessor(prof2);
	p.newAula(data, 2);
	p.newAula(data1, 9);
	p.marcarUtente(2, 1, 2, 4, data);
	p.marcarUtente(6, 1, 7, 9, data);
	p.marcarUtente(5, 1, 7, 9, data);
	//p.printOcupacaoPiscina(data, 2);
	p.printDia(data1); //INCORRETO, RESOLVER BUG
					   //p.printFrequenciaUtente(3);
					   //p.printProfessor(7);
	p.printProfessores();
	int coco;
	cin >> coco;




	int r = 0; // escolha de menu
	int c = 0; //escolha de sub menu utente
	int d = 0; // escolha de sub menu prof
	fstream file;
	fstream file2;
	string x;
	string y;
	
	string professores;
	string newutente;

	ostringstream z;
	string ut;
	string pr;

	// Passar ficheiro de utentes para um vetor           Ver pormenor no fim
	cout << "Introduza o nome do ficheiro de utentes a usar\n";
	cin >> x;

	file.open(x.c_str(), fstream::in);  //Abrir o ficheiro
	if (file.fail())					//Verificar se ficheiro existe
		cout << "Ficheiro pretendido nao encontrado!\n";
	else
	{
		while (getline(file, ut))
		{
			//extrair do getline info para o objeto criar esse objeto e depois chamar a funcao addUtente 
			string  name;
			string ide;
			string age;
			string periodos_por_pagar;
			string aulas_por_pagar;


			stringstream ss; ss.str(ut);
			
			getline(ss, ide, ';');
			ide.pop_back();

			getline(ss, name, ';');
			name.pop_back();

			getline(ss, age, ';');
			age.pop_back();

			getline(ss, aulas_por_pagar, ';');
			aulas_por_pagar.pop_back();

			getline(ss, periodos_por_pagar, ';');
			periodos_por_pagar.pop_back();

			
			int age_int = stoi(age);
			int ide_int = stoi(ide);
			int aulas_por_pagar_int = stoi(aulas_por_pagar);
			int periodos_por_pagar_int = stoi(periodos_por_pagar);

			Utente u1 = Utente(name, age_int, ide_int);
			u1.setRelPeriodosPorPagar(aulas_por_pagar_int, periodos_por_pagar_int);
			p.getUtentes.push_back(ut);               //esta a fazer push_back para uma copia ---- resolver
		}
		file.close();
	}


	// Passar ficheiro de professores para um vetor
	cout << "Introduza o nome do ficheiro de professores a usar\n";
	cin >> y;

	file2.open(y.c_str(), fstream::in);  //Abrir o ficheiro
	if (file2.fail())					//Verificar se ficheiro existe
		cout << "Ficheiro pretendido nao encontrado!\n";
	else
	{
		while (getline(file2, pr))
		{
		
			string  name;
			string ide;
			string age;
			string classes;

			stringstream ss2; ss2.str(pr);

			getline(ss2, ide, ';');
			ide.pop_back();

			getline(ss2, name, ';');
			name.pop_back();

			getline(ss2, age, ';');
			age.pop_back();

			getline(ss2, classes, ';');
			classes.pop_back();



			int age_int = stoi(age);
			int ide_int = stoi(ide);
			int classes_int = stoi(classes);
			

			Professor pr1 = Professor(name, age_int, ide_int, classes_int);
			p.getProfessores.push_back(pr);               //esta a fazer push_back para uma copia ---- resolver
		}
		file2.close();
	}




	while (r != 5) {
		r = getMenu("Utentes, Professores, Aulas, Ocupacao ,Quit (guarda alteracoes)", 1, 5);
		switch (r)
		{


		case 1:
			cout << "--------------------" << endl << "1. Ler Utentes\n" << "2. Criar Utente\n" << "3.  Apagar Utente\n" << "4. Pagar Mes\n" << "--------------------\n\n";
			cout << "Introduz um numero: \n> ";
			cin >> c;
			cin.clear();

			switch (c)
			{
			case 1:				//esta bem

				for (unsigned int i = 0; i < p.getUtentes.size(); i++)   //Enquanto o nr de linhas do ficheiro for menor do que o que foi mostrado ele continua a mostrar
					cout << p.getUtentes[i] << endl;
				break;


			case 2:				//esta bem
				file.open(x, fstream::in | fstream::out | fstream::app);
				string nome;
				int idade;
				cout << "Introduza o nome do novo utente\n";
				cin.clear();
				cin.ignore(1000, '\n');
				getline(cin, nome);
				cout << "Introduza a idade do novo utente\n";
				cin >> idade;

				Utente u1 = Utente(nome, idade);

				file << u1.getId() << " ; " << u1.getNome() << " ; " << idade << " ; " << "0" << " ; " << "0" << " ; " << " ; 0\n";

				p.addUtente(u1);
				file.close();
				cout << "\n" << "Done" << endl;
				break;
			}
			break; 



		case 2:

			cout << "--------------------" << endl << "1. Ler Professores\n" << "2. Criar Professor\n" << "3.  Apagar Professor\n" <<  "--------------------\n\n";
			cout << "Introduz um numero: \n> ";
			cin >> d;
			cin.clear();

			switch (d)
			{
			case 1:  //Mostra professores

				for (unsigned int i = 0; i < professores.size(); i++)   //Enquanto o nr de linhas do ficheiro for menor do que o que foi mostrado ele continua a mostrar
					cout << professores[i] << endl;
				break;


			case 2:   //Adiciona Professor     Esta bem acho
				file.open(y, fstream::in | fstream::out | fstream::app);
				string nome2;
				int idade;
				cout << "Introduza o nome do novo professor\n";
				cin.clear();
				cin.ignore(1000, '\n');
				getline(cin, nome2);
				cout << "Introduza a idade do novo professor\n";
				cin >> idade;

				Professor p1 = Professor(nome2, idade);
				
				file << p1.getId() << " ; " << p1.getNome() << " ; " << idade << " ; " << "0" << " ; 0\n";

				p.addProfessor(p1);
				file.close();
				cout << "\n" << "Done" << endl;
				break;

			case 3: //Remove Professor
			}
			break;


		case 3: //Aulas

		//case 4: //Ocupacao



		}

	}
}
