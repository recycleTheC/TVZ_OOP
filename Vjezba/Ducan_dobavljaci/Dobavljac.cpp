#include "Dobavljac.h"

Dobavljac::Dobavljac(string ime, int id, bool tip) : naziv(ime), broj(id), strani(tip) {
	if (tip) _strani_dobavljaci++;
}

int Dobavljac::brojStranih() {
	return _strani_dobavljaci;
}

string Dobavljac::getNaziv() const { return this->naziv; }
int Dobavljac::getBroj() const { return this->broj; }
bool Dobavljac::getStrani() const { return this->strani; }