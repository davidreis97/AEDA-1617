#include "Data.h"
#include <ostream>
#include <string>

using namespace std;

ostream & Data::operator<<(ostream &os) {
	string mestexto;
	switch (this->mes) {
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
		DataInvalida(this);
	};
	os << this->dia << " de " << mestexto << " de " << this->ano;
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

DataInvalida::DataInvalida(Data *data): data(data){}