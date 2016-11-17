// AEDA-1617.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "Piscina.h"

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
}