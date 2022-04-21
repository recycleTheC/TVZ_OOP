#include "Cvijet.h"

namespace Hortikultura {
	Cvijet::Cvijet(string vrsta, string boja, int kolicina) : vrsta(vrsta), boja(boja), kolicina(kolicina) {
		cout << "Cvijet constructor called" << endl;
	}

	Cvijet::~Cvijet(){
		cout << "Cvijet destructor called" << endl;
	}

	string Cvijet::getVrsta() const { return this->vrsta; }
	string Cvijet::getBoja() const { return this->boja; }
	string Cvijet::toString() const { return this->vrsta + " " + this->boja + " x" + to_string(this->kolicina); }
	int Cvijet::getKolicina() const { return this->kolicina; }

	void Cvijet::setVrsta(string vrsta) {
		this->vrsta = vrsta;
	}

	void Cvijet::setBoja(string boja) {
		this->boja = boja;
	}

	void Cvijet::setKolicina(int kolicina) {
		this->kolicina = kolicina;
	}
}