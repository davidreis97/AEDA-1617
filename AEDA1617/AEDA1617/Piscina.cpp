#include "Piscina.h"


using namespace std;
Piscina::Piscina(unsigned int periodos, float precoA, float precoP, unsigned int nMax) : periodoDia(periodos), nMaxUtentes(nMax){
	precoAula = precoA;
	precoPeriodo = precoP;
}

vector<Utente> Piscina::getUtentes() {
	return utentes;
}

vector<Professor> Piscina::getProfessores() {
	return professores;
}

bool Piscina::addUtente(Utente u) {
	if (std::find(utentes.begin(), utentes.end(), u) == utentes.end()) {
		utentes.push_back(u);
		return true;
	}
	else {
		return false;
	}
}

bool Piscina::addProfessor(Professor p) {
	if (std::find(professores.begin(), professores.end(), p) == professores.end()) {
		professores.push_back(p);
		return true;
	}
	else {
		return false;
	}
}

bool Piscina::addData(Data d) {
	if (std::find(horario.begin(), horario.end(), d) == horario.end()) {
		horario.push_back(d);
		return true;
	}
	else {
		return false;
	}
}

int Piscina::getNumUtentesAtuais(int periodo, Data data) {
	int i;
	for (i= 0; i < this->horario.size(); i++) {
		if (data == this->horario[i]) {
			break;
		}
	}
	if (i == this->horario.size()) {
		throw DataNaoEncontrada(&data);
	}
	return (this->horario[i].getPeriodo(periodo)->getNumUtentes());
}

int Piscina::getNumUtentesAula(int periodo, Data data) {
	int i;
	for (i = 0; i < this->horario.size(); i++) {
		if (data == this->horario[i]) {
			break;
		}
	}
	if (i == this->horario.size()) {
		throw DataNaoEncontrada(&data);
	}
	return (this->horario[i].getAula(periodo)->getNumUtentes());
}

bool Piscina::newAula(Data data, int periodo) {
	int j, i, menor = 0;
	for (j = 0; j < this->horario.size(); j++) {
		if (this->horario[j] == data) {
			break;
		}
	}
	if (j = this->horario.size()) {
		this->horario.push_back(data);
	}
	if (this->horario[j].getAula(periodo) != NULL) {
		return false;
	}
	for (int p = 0; p < this->professores.size(); p++) {
		if(this->professores[menor].getNumAulas() > this->professores[p].getNumAulas()) {
			menor = p;
		}
	}
	Aula aula(&(this->professores[menor]), periodo);
	if (i = this->horario[j].getAulas()->size()) {
		this->horario[j].getAulas()->push_back(aula);
		return true;
	}
}

void Piscina::marcarUtente(int id, bool isAula, int periodoInicial, int periodoFinal, Data data) {
	int i, j;
	for (i = 0; i < this->utentes.size(); i++) {
		if (this->utentes[i].getId() == id) {
			break;
		}
	}
	if (i == this->utentes.size()) {
		throw UtenteNaoEncontrado(id);
	}
	for (j = 0; j < this->horario.size(); j++) {
		if (this->horario[j] == data) {
			break;
		}
	}
	if (j = this->horario.size()) {
		this->horario.push_back(data);
	}
	if (this->getNumUtentesAtuais(periodoInicial, data) + this->getNumUtentesAula(periodoInicial, data) > this->nMaxUtentes) {
		throw PiscinaCheia(this->nMaxUtentes);
	}
	if (isAula) {
		if ((periodoInicial-periodoFinal) != 2) {
			cout << "Quantidade de Periodos Invalidos. Aulas são de duração 1 hora." << endl;
		}
		if (this->horario[j].getAula(periodoInicial) != NULL) {
			for (int p = periodoInicial; p < periodoFinal + 1; p++) {
				this->horario[j].getAula(periodoInicial)->addUtente(&(this->utentes[i]));
				this->utentes[i].setRelPeriodosPorPagar(1, 0);
			}
		}
	}
	if (this->horario[j].getAula(periodoInicial) != NULL) {
		for (int p = periodoInicial; p < periodoFinal + 1; p++) {
			this->horario[j].getAula(periodoInicial)->addUtente(&(this->utentes[i]));
			this->utentes[i].setRelPeriodosPorPagar(0, 1);
		}
	}
}

void Piscina::pagarUtente(int id, int mes) {
	int i, j, p, k;
	float pagamento = 0;
	for (i = 0; i < this->utentes.size(); i++) {
		if (this->utentes[i].getId() == id) {
			break;
		}
	}
	if (i == this->utentes.size()) {
		throw UtenteNaoEncontrado(id);
	}
	cout << "O utente " << this->utentes[i].getNome() << " com o ID " << this->utentes[i].getId() << " frequentou os seguintes periodos/aulas: " << endl;
	for (j = 0; j < this->horario.size; j++) {
		if (this->horario[j].getMes() == mes) {
			for (p = 0; p < this->horario[j].getPeriodos()->size(); p++) {
				for (k = 0; k < this->horario[j].getPeriodos()->at(p).getUtentes()->size; k++) {
					if (this->horario[j].getPeriodos()->at(p).getUtentes()->at(k)->getId() == id) {
						cout << this->horario[j] << " - Periodo " << this->horario[j].getPeriodos()->at(p).getPeriodo() << endl;
						pagamento += this->precoPeriodo;
					}
				}
			}
			for (p = 0; p < this->horario[j].getAulas()->size(); p++) {
				for (k = 0; k < this->horario[j].getAulas()->at(p).getUtentes()->size; k++) {
					if (this->horario[j].getAulas()->at(p).getUtentes()->at(k)->getId() == id) {
						cout << this->horario[j] << " - Aula no Periodo " << this->horario[j].getAulas()->at(p).getPeriodo() << endl;
						pagamento += this->precoAula;
					}
				}
			}
		}
	}
	cout << "Devendo efetuar um pagamento de " << pagamento << "€ por este mes." << endl;
	}

PiscinaCheia::PiscinaCheia(int nMaxUtentes):nMaxUtentes(nMaxUtentes) {}

int PiscinaCheia::getNMaxUtentes() {
	return this->nMaxUtentes;
}

void Piscina::printOcupacaoPiscina(Data data, int periodo) {
	int j;
	for (j = 0; j < this->horario.size(); j++) {
		if (this->horario[j] == data) {
			break;
		}
	}
	if (j = this->horario.size()) {
		throw DataNaoEncontrada(&data);
	}
	cout << "Frequencia da piscina no periodo " << periodo << " do dia " << data << ":" << endl;
	for (int i = 0; i < this->horario[j].getPeriodo(periodo)->getUtentes()->size(); i++) {
		cout << "Utente " << this->horario[j].getPeriodo(periodo)->getUtentes()->at(i)->getNome() << " com ID " << this->horario[j].getPeriodo(periodo)->getUtentes()->at(i)->getId() << endl;
	}
	for (int i = 0; i < this->horario[j].getAula(periodo)->getUtentes()->size(); i++) {
		cout << "Aluno " << this->horario[j].getPeriodo(periodo)->getUtentes()->at(i)->getNome() << " com ID " << this->horario[j].getPeriodo(periodo)->getUtentes()->at(i)->getId() << endl;
	}
}

void Piscina::printFrequenciaUtente(int id) {
	int i;
	for (i = 0; i < this->utentes.size(); i++) {
		if (this->utentes[i].getId() == id) {
			break;
		}
	}
	if (i == this->utentes.size()) {
		throw UtenteNaoEncontrado(id);
	}
	cout << "O utente " << this->utentes[i].getNome() << " com ID " << this->utentes[i].getId() << " frequentou " << this->utentes[i].getPeriodosPorPagar() << " periodos e " << this->utentes[i].getAulasPorPagar() << " aulas, aguardando pagamento de " << this->utentes[i].valorPagamento(this->precoAula, this->precoPeriodo) << "€" << endl;
}

void Piscina::printProfessor(int id) {
	int j;
	for (j = 0; j < this->professores.size(); j++) {
		if (this->professores[j].getId() == id) {
			break;
		}
	}
	if (j == this->professores.size()) {
		throw UtenteNaoEncontrado(id);
	}
	cout << "O professor " << this->professores[j].getNome() << "com o ID " << this->professores[j].getId() << " lecionou " << this->professores[j].getNumAulas() << " aulas." << endl;
}

void Piscina::printDia(Data data) {
	for (int i = 0; i < this->periodoDia; i++) {
		try {
			this->printOcupacaoPiscina(data, i);
		}
		catch (DataNaoEncontrada data) {
			cout << "A data fornecida (" << data.getData() << ") não pertence aos nossos registos." << endl;
		}
		
	}
}