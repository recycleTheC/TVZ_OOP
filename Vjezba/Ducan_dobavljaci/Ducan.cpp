#include "Ducan.h"

Ducan& Ducan::Dodaj(Dobavljac d) {
	this->dobavljaci.push_back(d);
	return *this;
}

ostream& operator << (ostream& izlaz, const Ducan& d) {
	for (int i = 0; i < d.dobavljaci.size(); i++)
	{
		izlaz << "Dobavljac: " << d.dobavljaci[i].getBroj() << " - " << d.dobavljaci[i].getNaziv() << ", " << (d.dobavljaci[i].getStrani() ? "strani" : "domaci") << endl;
	}

	return izlaz;
}

void Ducan::operator -= (const int id) {
	bool postoji = false;

	for (int i = 0; i < this->dobavljaci.size(); i++)
	{
		if (this->dobavljaci[i].getBroj() == id) {
			postoji = true;
			this->dobavljaci.erase(this->dobavljaci.begin() + i);
			break;
		}
	}

	if (!postoji) throw DobavljacIznimka(id);
}

Ducan::operator int() { return this->dobavljaci.size(); }