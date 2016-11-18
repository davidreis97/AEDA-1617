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
		this->horario.push_back(d);
		for (int i = 0; i < this->periodoDia; i++) {
			this->horario.back().addPeriodo(i);
		}
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
		this->addData(data);
	}
	if (this->horario[i].getPeriodo(periodo) != NULL) {
		return (this->horario[i].getPeriodo(periodo)->getNumUtentes());
	}
	return 0;
}

int Piscina::getNumUtentesAula(int periodo, Data data) {
	int i;
	for (i = 0; i < this->horario.size(); i++) {
		if (data == this->horario[i]) {
			break;
		}
	}
	if (i == this->horario.size()) {
		this->addData(data);
	}
	if (this->horario[i].getAula(periodo) != NULL) {
		return (this->horario[i].getAula(periodo)->getNumUtentes());
	}
	return 0;
}

bool Piscina::newAula(Data data, int periodo) {
	int j, i, menor = 0;
	for (j = 0; j < this->horario.size(); j++) {
		if (this->horario[j] == data) {
			break;
		}
	}
	if (j == this->horario.size()) {
		this->addData(data);
	}
	if (this->horario[j].getAula(periodo) != NULL) {
		return false;
	}
	if (this->professores.size() > 0) {
		for (int p = 0; p < this->professores.size(); p++) {
			if (this->professores[menor].getNumAulas() > this->professores[p].getNumAulas()) {
				menor = p;
			}
		}
		this->horario[j].addAula(periodo, &(this->professores[menor]));
		this->horario[j].addAula(periodo+1, &(this->professores[menor]));
		this->professores[menor].setNumAulas(2);
		return true;
	}
	else {
		cout << "Nao ha um professor para essa aula." << endl;
		return false;
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
	if (j == this->horario.size()) {
		this->addData(data);
	}
	if (this->getNumUtentesAtuais(periodoInicial, data) + this->getNumUtentesAula(periodoInicial, data) > this->nMaxUtentes) {
		throw PiscinaCheia(this->nMaxUtentes);
	}
	if (isAula) {
		if ((periodoFinal-periodoInicial) != 2) {
			cout << "Quantidade de Periodos Invalidos. Aulas sao de duracao 1 hora." << endl;
		}
		if (this->horario[j].getAula(periodoInicial) != NULL) {
			for (int p = periodoInicial; p < periodoFinal; p++) {
					this->horario[j].getAula(p)->addUtente(&(this->utentes[i]));
					this->utentes[i].setRelPeriodosPorPagar(1, 0);
			}
		}
	}
	else {
		if (this->horario[j].getPeriodo(periodoInicial) != NULL) {
			for (int p = periodoInicial; p < periodoFinal; p++) {
				this->horario[j].getPeriodo(p)->addUtente(&(this->utentes[i]));
				this->utentes[i].setRelPeriodosPorPagar(0, 1);
			}
		}
		else {

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
	for (j = 0; j < this->horario.size(); j++) {
		if (this->horario[j].getMes() == mes) {
			for (p = 0; p < this->horario[j].getPeriodos()->size(); p++) {
				for (k = 0; k < this->horario[j].getPeriodos()->at(p).getUtentes()->size(); k++) {
					if (this->horario[j].getPeriodos()->at(p).getUtentes()->at(k)->getId() == id) {
						cout << this->horario[j] << " - Periodo " << this->horario[j].getPeriodos()->at(p).getPeriodo() << endl;
						pagamento += this->precoPeriodo;
					}
				}
			}
			for (p = 0; p < this->horario[j].getAulas()->size(); p++) {
				for (k = 0; k < this->horario[j].getAulas()->at(p).getUtentes()->size(); k++) {
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
	if (j == this->horario.size()) {
		throw DataNaoEncontrada(&data);
	}
	cout << "Frequencia da piscina no periodo " << periodo << " do dia " << data << ":" << endl;
	if (this->horario[j].getAula(periodo) != NULL || this->horario[j].getPeriodo(periodo) != NULL) {
		if (this->horario[j].getPeriodo(periodo) != NULL) {
			for (int i = 0; i < this->horario[j].getPeriodo(periodo)->getUtentes()->size(); i++) {
				cout << "Utente " << this->horario[j].getPeriodo(periodo)->getUtentes()->at(i)->getNome() << " com ID " << this->horario[j].getPeriodo(periodo)->getUtentes()->at(i)->getId() << endl;
			}
		}
		if (this->horario[j].getAula(periodo) != NULL) {
			for (int i = 0; i < this->horario[j].getAula(periodo)->getUtentes()->size(); i++) {
				cout << "Aluno " << this->horario[j].getAula(periodo)->getUtentes()->at(i)->getNome() << " com ID " << this->horario[j].getAula(periodo)->getUtentes()->at(i)->getId() << endl;
			}
		}
	}
	else {
		cout << "Periodo Nao Encontrado" << endl;
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
	cout << "O professor " << this->professores[j].getNome() << " com o ID " << this->professores[j].getId() << " leccionou " << this->professores[j].getNumAulas() << " periodos de aulas." << endl;
}

void Piscina::printProfessores() {
	int j;
	for (j = 0; j < this->professores.size(); j++) {
		this->printProfessor(this->professores[j].getId());
	}	
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

bool Piscina::removeUtente(int id) {
	vector<Utente>::iterator it;
	for (it = this->utentes.begin(); it != this->utentes.end();) {
		if ((it)->getId() == id) {
			this->utentes.erase(it);
			return true;
		}
	}
	return false;
}

bool Piscina::removeProfessor(int id) {
	vector<Professor>::iterator it;
	for (it = this->professores.begin(); it != this->professores.end();) {
		if ((it)->getId() == id) {
			this->professores.erase(it);
			return true;
		}
	}
	return false;
}