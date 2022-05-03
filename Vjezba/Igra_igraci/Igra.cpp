#include "Igra.h"

Igra::Igra(string ime) : naziv(ime) {}

Igra& Igra::Dodaj(Igrac ig) {
	for (int i = 0; i < this->igraci.size(); i++)
		if (igraci[i].id == ig.id) throw IgracIznimka(ig.id);

	this->igraci.push_back(ig);
	return *this;
}

ostream& operator << (ostream& izlaz, const Igra& igra) {
	izlaz << igra.naziv << endl;
	for (int i = 0; i < igra.igraci.size(); i++)
	{
		izlaz << "- " << igra.igraci[i].id << endl;
	}

	return izlaz;
}

void Igra::operator += (Igrac ig) {
	this->Dodaj(ig);
}

Igra::operator int() {
	return this->igraci.size();
}