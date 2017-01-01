#include "Piscina.h"


using namespace std;
Piscina::Piscina(unsigned int periodos, float precoA, float precoP, unsigned int nMax) : periodoDia(periodos), nMaxUtentes(nMax), artigosDisponiveis(Artigo("",0,"")) {
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
	for (i = 0; i < this->horario.size(); i++) {
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

bool Piscina::newAula(Data data, int periodo, string modalidade) {
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
		this->horario[j].addAula(periodo, this->professores[menor], modalidade);
		this->horario[j].addAula(periodo + 1, this->professores[menor], modalidade);
		this->professores[menor].setNumAulas(2);
		return true;
	}
	else {
		cout << "Nao ha um professor para essa aula." << endl;
		return false;
	}

}

void Piscina::marcarUtente(int id, bool isAula, int periodoInicial, int periodoFinal, Data data, string modalidade) {
	int i, j;
	for (i = 0; i < this->utentes.size(); i++) {
		if (this->utentes[i].getId() == id) {
			break;
		}
	}
	if (i == this->utentes.size()) {
		throw PessoaNaoEncontrada(id);
	}
	for (j = 0; j < this->horario.size(); j++) {
		if (this->horario[j] == data) {
			break;
		}
	}
	if (j == this->horario.size()) {
		this->addData(data);
	}
	for (int k = periodoInicial; k <= periodoFinal; k++) {
		if (this->getNumUtentesAtuais(k, data) >= this->nMaxUtentes) {
			throw PiscinaCheia(this->nMaxUtentes);
		}
	}
	if (isAula) {
		if ((periodoFinal - periodoInicial) != 1) {
			cout << "Quantidade de Periodos Invalidos. Aulas sao de duracao 1 hora." << endl;
		}
		else {
			if (this->horario[j].getAula(periodoInicial) != NULL && this->horario[j].getAula(periodoFinal) != NULL && this->horario[j].getAula(periodoInicial)->getModalidade() == modalidade && this->horario[j].getAula(periodoFinal)->getModalidade() == modalidade) {
					this->horario[j].getAula(periodoInicial)->addUtente(this->utentes[i]);
					this->horario[j].getAula(periodoFinal)->addUtente(this->utentes[i]);
					this->utentes[i].setRelPeriodosPorPagar(2, 0);
			}
			else {
				cout << "Aula Inexistente. Verifique se ja criou a aula com a modalidade correta e se existe pelo menos um professor disponivel." << endl;
			}
		}
	}
	else {
		if ((periodoFinal - periodoInicial) > 3) {
			cout << "Quantidade de Periodos Invalidos. Periodos livres sao de duracao maxima de 2 horas. (4 periodos)" << endl;
		}
		else {
			for (int p = periodoInicial; p <= periodoFinal; p++) {
				this->horario[j].getPeriodo(p)->addUtente(this->utentes[i]);
				this->utentes[i].setRelPeriodosPorPagar(0, 1);
			}
		}
	}
}

void Piscina::pagarUtente(int id, int mes, int ano) {
	int i, j, p, k;
	float pagamento = 0;
	for (i = 0; i < this->utentes.size(); i++) {
		if (this->utentes[i].getId() == id) {
			break;
		}
	}
	if (i == this->utentes.size()) {
		throw PessoaNaoEncontrada(id);
	}
	cout << "O utente " << this->utentes[i].getNome() << " com o ID " << this->utentes[i].getId() << " frequentou os seguintes periodos/aulas: " << endl;
	for (j = 0; j < this->horario.size(); j++) {
		if (this->horario[j].getMes() == mes && this->horario[j].getAno() == ano) {
			for (p = 0; p < this->horario[j].getPeriodos()->size(); p++) {
				for (k = 0; k < this->horario[j].getPeriodos()->at(p).getUtentes()->size(); k++) {
					if (this->horario[j].getPeriodos()->at(p).getUtentes()->at(k).getId() == id) {
						cout << this->horario[j] << " - Periodo " << this->horario[j].getPeriodos()->at(p).getPeriodo() << endl;
						pagamento += this->precoPeriodo;
					}
				}
			}
			for (p = 0; p < this->horario[j].getAulas()->size(); p++) {
				for (k = 0; k < this->horario[j].getAulas()->at(p).getUtentes()->size(); k++) {
					if (this->horario[j].getAulas()->at(p).getUtentes()->at(k).getId() == id) {
						cout << this->horario[j] << " - Aula no Periodo " << this->horario[j].getAulas()->at(p).getPeriodo() << endl;
						pagamento += this->precoAula;
					}
				}
			}
		}
	}
	cout << "Devendo efetuar um pagamento de " << pagamento << " Euros por este mes." << endl;
}

PiscinaCheia::PiscinaCheia(int nMaxUtentes) :nMaxUtentes(nMaxUtentes) {}

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
				cout << "Utente " << this->horario[j].getPeriodo(periodo)->getUtentes()->at(i).getNome() << " com ID " << this->horario[j].getPeriodo(periodo)->getUtentes()->at(i).getId() << endl;
			}
		}
		if (this->horario[j].getAula(periodo) != NULL) {
			for (int i = 0; i < this->horario[j].getAula(periodo)->getUtentes()->size(); i++) {
				cout << "Aluno " << this->horario[j].getAula(periodo)->getUtentes()->at(i).getNome() << " com ID " << this->horario[j].getAula(periodo)->getUtentes()->at(i).getId() << " em aula com o professor " << this->horario[j].getAula(periodo)->getProfessor().getNome() << endl;
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
		throw PessoaNaoEncontrada(id);
	}
	cout << "O utente " << this->utentes[i].getNome() << " com o ID " << this->utentes[i].getId() << " frequentou os seguintes periodos/aulas: " << endl;
	for (int j = 0; j < this->horario.size(); j++) {
		for (int p = 0; p < this->horario[j].getPeriodos()->size(); p++) {
			for (int k = 0; k < this->horario[j].getPeriodos()->at(p).getUtentes()->size(); k++) {
				if (this->horario[j].getPeriodos()->at(p).getUtentes()->at(k).getId() == id) {
					cout << this->horario[j] << " - Periodo " << this->horario[j].getPeriodos()->at(p).getPeriodo() << endl;
				}
			}
		}
		for (int p = 0; p < this->horario[j].getAulas()->size(); p++) {
			for (int k = 0; k < this->horario[j].getAulas()->at(p).getUtentes()->size(); k++) {
				if (this->horario[j].getAulas()->at(p).getUtentes()->at(k).getId() == id) {
					cout << this->horario[j] << " - Aula no Periodo " << this->horario[j].getAulas()->at(p).getPeriodo() << " em aula com o professor " << this->horario[j].getAulas()->at(p).getProfessor().getNome() << endl;
				}
			}
		}
	}
}

void Piscina::printProfessor(int id) {
	int j;
	for (j = 0; j < this->professores.size(); j++) {
		if (this->professores[j].getId() == id) {
			break;
		}
	}
	if (j == this->professores.size()) {
		throw PessoaNaoEncontrada(id);
	}
	cout << "O professor " << this->professores[j].getNome() << " com o ID " << this->professores[j].getId() << " leccionou as seguintes aulas: " << endl;
	for (int k = 0; k < this->horario.size(); k++) {
		for (int p = 0; p < this->horario[k].getAulas()->size(); p++) {
			if (this->horario[k].getAulas()->at(p).getProfessor().getId() == id) {
				cout << this->horario[k] << " - Aula no Periodo " << this->horario[k].getAulas()->at(p).getPeriodo() << endl;
			}
		}

	}
}

void Piscina::printProfessores() {
	int j;
	for (j = 0; j < this->professores.size(); j++) {
		try {
			this->printProfessor(this->professores[j].getId());
		}
		catch (PessoaNaoEncontrada pne) {
			cout << "Erro na funcao printFrequenciaUtentes. (ID " << pne.getId() << " nao encontrado)" << endl;
		}
	}
}

void Piscina::printDia(Data data) {
	for (int i = 0; i < this->periodoDia; i++) {
		try {
			this->printOcupacaoPiscina(data, i);
		}
		catch (DataNaoEncontrada data) {
			cout << "A data fornecida (" << data.getData() << ") nao pertence aos nossos registos." << endl;
			break;
		}

	}
}

bool Piscina::removeUtente(int id) {
	for (int j = 0; j < this->horario.size(); j++) {
		for (int p = 0; p < this->horario[j].getPeriodos()->size(); p++) {
			for (int k = 0; k < this->horario[j].getPeriodos()->at(p).getUtentes()->size();) {
				if (this->horario[j].getPeriodos()->at(p).getUtentes()->at(k).getId() == id) {
					this->horario[j].getPeriodos()->at(p).getUtentes()->erase(this->horario[j].getPeriodos()->at(p).getUtentes()->begin() + k);
				}
				else {
					k++;
				}
			}
		}
		for (int p = 0; p < this->horario[j].getAulas()->size(); p++) {
			for (int k = 0; k < this->horario[j].getAulas()->at(p).getUtentes()->size();) {
				if (this->horario[j].getAulas()->at(p).getUtentes()->at(k).getId() == id) {
					this->horario[j].getAulas()->at(p).getUtentes()->erase(this->horario[j].getAulas()->at(p).getUtentes()->begin() + k);
				}
				else {
					k++;
				}
			}
		}
	}
	vector<Utente>::iterator it;
	for (it = this->utentes.begin(); it != this->utentes.end();) {
		if ((it)->getId() == id) {
			this->utentes.erase(it);
			return true;
		}
		else {
			it++;
		}
	}
	return false;
}

bool Piscina::removeProfessor(int id) {
	int menor = -1;
	for (int j = 0; j < this->professores.size(); j++) {
		if (this->professores[j].getId() != id) {
			menor = j;
		}
	}
	if (menor == -1) {
		cout << "Nao ha professores suficientes para esta operacao." << endl;
		return false;
	}
	for (int k = 0; k < this->horario.size(); k++) {
		for (int p = 0; p < this->horario[k].getAulas()->size(); p++) {
			if (this->horario[k].getAulas()->at(p).getProfessor().getId() == id) {
				for (int j = 0; j < this->professores.size(); j++) {
					if (this->professores[menor].getNumAulas() > this->professores[j].getNumAulas() && this->professores[j].getId() != id) {
						menor = j;
					}
				}
				this->horario[k].getAulas()->at(p).setProfessor(this->professores[menor]);
				this->horario[k].getAulas()->at(p+1).setProfessor(this->professores[menor]);
				this->professores[menor].setNumAulas(2);
			}
		}
	}
	vector<Professor>::iterator it;
	for (it = this->professores.begin(); it != this->professores.end();) {
		if ((it)->getId() == id) {
			this->professores.erase(it);
			return true;
		}
		else {
			it++;
		}
	}
	return false;
}

bool Piscina::importUtentes(string x) {
	ostringstream z;
	string ut;
	fstream file;
	file.open(x.c_str(), fstream::in);  //Abrir o ficheiro
	if (file.fail())					//Verificar se ficheiro existe
		cout << "Ficheiro pretendido nao encontrado!\n";
	else {
		while (!file.eof()) {
			while (getline(file, ut)) {
				string name;
				string age;
				string periodos_por_pagar;
				string aulas_por_pagar;

				stringstream ss; ss.str(ut);

				getline(ss, name, ';');
				name.pop_back();

				getline(ss, age, ';');
				age.pop_back();

				getline(ss, aulas_por_pagar, ';');
				aulas_por_pagar.pop_back();

				getline(ss, periodos_por_pagar, ';');
				periodos_por_pagar.pop_back();

				int age_int = stoi(age);
				int aulas_por_pagar_int = stoi(aulas_por_pagar);
				int periodos_por_pagar_int = stoi(periodos_por_pagar);

				Utente u1 = Utente(name, age_int);
				u1.setAbsPeriodosPorPagar(aulas_por_pagar_int, periodos_por_pagar_int);
				this->addUtente(u1);
			}
		}
		file.close();
	}
	return true;
}



bool Piscina::exportUtentes(string x) {
	ofstream file2;
	file2.open(x);
	for (int i = 0; i < this->utentes.size(); i++) {
		file2 << this->utentes[i].getNome() << " ;" << this->utentes[i].getIdade() << " ;" << this->utentes[i].getAulasPorPagar() << " ;" << this->utentes[i].getPeriodosPorPagar() << " ;" << endl;
	}
	file2.close();
	return true;
}


bool Piscina::importProfessores(string x) {
	ostringstream z;
	string ut;
	fstream file;
	file.open(x.c_str(), fstream::in);  //Abrir o ficheiro
	if (file.fail())					//Verificar se ficheiro existe
		cout << "Ficheiro pretendido nao encontrado!\n";
	else {
		while (!file.eof()) {
			while (getline(file, ut)) {
				string name;
				string age;

				stringstream ss; ss.str(ut);

				getline(ss, name, ';');
				name.pop_back();

				getline(ss, age, ';');
				age.pop_back();


				int age_int = stoi(age);

				Professor p1 = Professor(name, age_int);
				this->addProfessor(p1);
			}
		}
		file.close();
	}
	return true;
}

bool Piscina::exportProfessores(string x) {
	ofstream file2;
	file2.open(x);
	for (int i = 0; i < this->professores.size(); i++) {
		file2 << this->professores[i].getNome() << " ;" << this->professores[i].getIdade() << " ;" << endl;
	}
	file2.close();
	return true;
}

void Piscina::printFrequenciaUtentes() {
	for (int i = 0; i < this->utentes.size(); i++) {
		try {
			this->printFrequenciaUtente(this->utentes[i].getId());
		}
		catch (PessoaNaoEncontrada pne) {
			cout << "Erro na funcao printFrequenciaUtentes. (ID " << pne.getId() << " nao encontrado)" << endl;
		}
	}
}

const unsigned int Piscina::getPeriodoDia() {
	return this->periodoDia;
}	

/*
* FUNCOES DA LOJA
*/

bool Piscina::comprarArtigo(Artigo art, int id) {
	int i;
	for (i = 0; i < this->utentes.size() && id != -1; i++) {
		if (this->utentes[i].getId() == id) {
			break;
		}
	}
	if (i == this->utentes.size() && id != -1) {
		throw PessoaNaoEncontrada(id);
	}
	if (this->artigosDisponiveis.find(art) == Artigo("", 0, "")) {
		throw ArtigoNaoEncontrado(art);
	}
	Artigo aux = this->artigosDisponiveis.find(art);
	if (!aux.addStock(-art.getStock())) {
		return false;
	}
	else {
		this->utentes[i].addArtigo(art);
		this->artigosDisponiveis.remove(art);
		if (aux.getStock()) {
			this->artigosDisponiveis.insert(aux);
		}
		return true;
	}
}

void Piscina::printArtigos() {
	for (BSTItrIn<Artigo> it(this->artigosDisponiveis); !it.isAtEnd(); it.advance()) {
		this->printStockArtigo(it.retrieve());
	}
}

void Piscina::printStockArtigo(Artigo art) {
	Artigo obtido = this->artigosDisponiveis.find(art);
	if (obtido == Artigo("", 0, "")) {
		throw ArtigoNaoEncontrado(art);
	}
	else {
		cout << obtido << endl;
	}
}

void Piscina::printArtigosCliente(int id) {
	int i;
	for (i = 0; i < this->utentes.size() && id != -1; i++) {
		if (this->utentes[i].getId() == id) {
			break;
		}
	}
	if (i == this->utentes.size() && id != -1) {
		throw PessoaNaoEncontrada(id);
	}
	for (int j = 0; j < this->utentes[i].getArtigos().size(); j++) {
		cout << this->utentes[i].getArtigos().at(j) << endl;
	}
}

void Piscina::adicionarStock(Artigo art) {
	Artigo aux = this->artigosDisponiveis.find(art);
	if (aux == Artigo("", 0, "")) {
		this->artigosDisponiveis.insert(art);
	}
	else {
		this->artigosDisponiveis.remove(art);
		aux.addStock(art.getStock());
		this->artigosDisponiveis.insert(aux);
	}
}


/*
* FUNCOES DAS MODALIDADES
*/

list<string> Piscina::getModalidades() {
	return modalidades;
}

bool Piscina::addModalidade(string m) {
	list<string>::iterator it;
	for (it = modalidades.begin(); it != modalidades.end(); it++) {
		if (*it == m)
			return false;
	}
	modalidades.push_back(m);
}

bool Piscina::removeModalidade(string m) {
	list<string>::iterator it;
	for (it = modalidades.begin(); it != modalidades.end(); it++) {
		if (*it == m) {
			modalidades.erase(it);
			return true;
		}
	}
	return false;
}

bool Piscina::isModalidade(string m) {
	list<string>::iterator it;
	for (it = modalidades.begin(); it != modalidades.end(); it++)
		if (*it == m)
			return true;
	return false;
}

InfoPiscina Piscina::piscinaMaisPerto(string m) {
	priority_queue<InfoPiscina> aux;
	aux = piscinas_viz;
	InfoPiscina p("Nome", -1);
	while (!aux.empty()) {
		p = aux.top();
		list<string>::iterator it;
		for (it = p.getModalidades().begin(); it != p.getModalidades().end(); it++) {
			if (*it == m) {
				return p;
			}
		}
		aux.pop();
	}
	return p;
}

priority_queue<InfoPiscina> Piscina::getPiscinas_Viz() {
	return piscinas_viz;
}

bool Piscina::addInfoPiscina(InfoPiscina infoP) {
	priority_queue<InfoPiscina> aux;
	aux = piscinas_viz;
	while (!aux.empty()) {
		if (aux.top() == infoP) {
			return false;
		}
		aux.pop();
	}
	this->piscinas_viz.push(infoP);
	return true;
}

/*
* FUNCOES DOS UTENTES INATIVOS
*/

void Piscina::gerarUtentesInativos(Data dataAtual) {
	vector<Utente> aux;
	for (int j = 0; j < this->horario.size(); j++) {
		if (dataAtual - this->horario[j] < 180) { //180 dias = 6 meses
			for (int p = 0; p < this->horario[j].getPeriodos()->size(); p++) {
				for (int k = 0; k < this->horario[j].getPeriodos()->at(p).getUtentes()->size(); k++) {
					aux.push_back(this->horario[j].getPeriodos()->at(p).getUtentes()->at(k));
				}
			}
			for (int p = 0; p < this->horario[j].getAulas()->size(); p++) {
				for (int k = 0; k < this->horario[j].getAulas()->at(p).getUtentes()->size(); k++) {
					aux.push_back(this->horario[j].getAulas()->at(p).getUtentes()->at(k));
				}
			}
		}
	}
	for (int j = 0; j < this->utentes.size(); j++) {
		if (find(aux.begin(), aux.end(), this->utentes[j]) == aux.end() && find(this->utentesInativos.begin(), this->utentesInativos.end(), this->utentes[j]) == this->utentesInativos.end()) {
			this->utentesInativos.insert(this->utentes[j]);
		}
		if (find(aux.begin(), aux.end(), this->utentes[j]) != aux.end() && find(this->utentesInativos.begin(), this->utentesInativos.end(), this->utentes[j]) != this->utentesInativos.end()) {
			this->utentesInativos.erase(this->utentes[j]);
		}
	}
}

void Piscina::changeIdadeUtente(unsigned int idade, int id) {
	int j;
	for (j = 0; j < this->utentes.size(); j++) {
		if (this->utentes[j].getId() == id) {
			this->utentes[j].setIdade(idade);
			break;
		}
	}
	if (j == this->utentes.size()) {
		throw PessoaNaoEncontrada(id);
	}
	if (find(this->utentesInativos.begin(), this->utentesInativos.end(), this->utentes[j]) != this->utentesInativos.end()) {
		this->utentesInativos.erase(this->utentes[j]);
		this->utentesInativos.insert(this->utentes[j]); //Nesta segunda insercao ja tera a idade correta.
	}
}

void Piscina::printUtentesInativos() {
	cout << "Utentes Inativos: " << endl;
	for (tabDisp::iterator it = this->utentesInativos.begin(); it != this->utentesInativos.end(); it++) {
		cout << "Utente " << (*it).getId() << " - " << (*it).getNome() << " de " << (*it).getIdade() << " anos." << endl;
	}
}

void Piscina::printAtividadeUtente(int id) {
	Utente aux("", 0, id);
	if (find(this->utentes.begin(), this->utentes.end(), aux) == this->utentes.end()) {
		throw PessoaNaoEncontrada(id);
	}
	if(find(this->utentesInativos.begin(), this->utentesInativos.end(), aux) != this->utentesInativos.end()) {
		cout << "O cliente esta inativo." << endl;
	}
	else {
		cout << "O cliente esta ativo." << endl;
	}
}