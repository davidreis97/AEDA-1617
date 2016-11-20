#include "Data.h"
#include <ostream>
#include <string>

using namespace std;

bool Data::operator<(Data otherdata) {
	if (this->ano < otherdata.getAno()) {
		return 1;
	}else if(this->ano > otherdata.getAno()){
		return 0;
	}else {
		if (this->mes < otherdata.getMes()) {
			return 1;
		}else if (this->mes > otherdata.getMes()) {
			return 0;
		}else {
			if (this->dia < otherdata.getDia()) {
				return 1;
			}else{
				return 0;
			}
		}
	}
}

ostream & operator<<(ostream &os,Data& data) {
	string mestexto = "Erro";
	switch (data.getMes()) {
	case(1):
		mestexto = "Janeiro";
		break;
	case(2):
		mestexto = "Fevereiro";
		break;
	case(3):
		mestexto = "Março";
		break;
	case(4):
		mestexto = "Abril";
		break;
	case(5):
		mestexto = "Maio";
		break;
	case(6):
		mestexto = "Junho";
		break;
	case(7):
		mestexto = "Julho";
		break;
	case(8):
		mestexto = "Agosto";
		break;
	case(9):
		mestexto = "Setembro";
		break;
	case(10):
		mestexto = "Outubro";
		break;
	case(11):
		mestexto = "Novembro";
		break;
	case(12):
		mestexto = "Dezembro";
		break;
	default:
		break;
	};
	os << data.getDia() << " de " << mestexto << " de " << data.getAno();
	return os;
}


Data::Data(unsigned short dia1, unsigned short mes1, unsigned short ano1) {
	this->ano = ano1;
	this->dia = dia1;
	this->mes = mes1;
	if (dia > 31 || mes > 12) {
		throw DataInvalida(this);
	}
}

unsigned short Data::getDia() {
	return this->dia;
}

unsigned short Data::getMes() {
	return this->mes;
}

unsigned short Data::getAno() {
	return this->ano;
}

vector<Periodo> *Data::getPeriodos() {
	return &(this->periodos);
}

DataInvalida::DataInvalida(Data *data): data(data){}

Data DataInvalida::getData() {
	return *(this->data);
}

DataNaoEncontrada::DataNaoEncontrada(Data* data) :data(data){}

Data DataNaoEncontrada::getData() {
	return *(this->data);
}

bool Data::operator==(Data otherdata) {
	if (this->ano == otherdata.getAno() && this->mes == otherdata.getMes() && this->dia == otherdata.getDia()) {
		return true;
	}
	else {
		return false;
	}
}

vector<Aula> *Data::getAulas() {
	return &(this->aulas);
}

Aula *Data::getAula(int periodo) {
	for (int i = 0; i < this->aulas.size(); i++) {
		if (this->aulas[i].getPeriodo() == periodo) {
			return &(this->aulas[i]);
		}
	}
	return NULL;
}

Periodo *Data::getPeriodo(int periodo) {
	for (int i = 0; i < this->periodos.size(); i++) {
		if (this->periodos[i].getPeriodo() == periodo) {
			return &(this->periodos[i]);
		}
	}
	return NULL;
}

void Data::addPeriodo(int i) {
	Periodo p(i);
	this->periodos.push_back(p);
}

void Data::addAula(int i, Professor p) {
	Aula a(p,i);
	this->aulas.push_back(a);
}
