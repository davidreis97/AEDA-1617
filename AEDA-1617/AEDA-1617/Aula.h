#pragma once

class Periodo {
	vector<Utente *> utentes;
};

class Aula : public Periodo {
private:
	Professor *professor;
};