#include "Klub.h"

Klub::Klub() = default;

Klub::Klub(string naziv, string adresa) : naziv(naziv), adresa(adresa) {}

Klub::~Klub() {
	if (this->trener != NULL) delete this->trener;
}

Klub::Klub(const Klub& klub) {
	this->naziv = klub.naziv;
	this->adresa = klub.adresa;
	this->trener = new Osoba(*klub.trener);
}

Klub& Klub::operator = (const Klub& klub) {
	if (this != &klub) {
		this->naziv = klub.naziv;
		this->adresa = klub.adresa;
		this->trener = new Osoba(*klub.trener);
	}

	return *this;
}

string Klub::getNaziv() const { return this->naziv; }
string Klub::getAdresa() const { return this->adresa; }
Osoba* Klub::getTrener() const { return this->trener; }

void Klub::setNaziv(string naziv) {
	this->naziv = naziv;
}

void Klub::setAdresa(string adresa) {
	this->adresa = adresa;
}

void Klub::setTrener(Osoba& trener) {
	this->trener = new Osoba(trener);
}