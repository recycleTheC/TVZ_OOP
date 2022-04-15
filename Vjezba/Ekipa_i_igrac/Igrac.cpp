#include "Igrac.h"

Igrac::Igrac() {}
Igrac::~Igrac() {}
Igrac::Igrac(string ime, string prezime) : ime(ime), prezime(prezime) {}

string Igrac::ispisi() const {
	return ime + " " + " " + prezime + " (" + to_string(brojDresa) + "), " + to_string(trzisnaCijena);
}

string Igrac::getIme() const {
	return ime;
}

string Igrac::getPrezime() const {
	return prezime;
}

int Igrac::getBrojDresa() const {
	return brojDresa;
}

double Igrac::getTrzisnaCijena() const {
	return trzisnaCijena;
}

void Igrac::setIme(string ime) {
	this->ime = ime;
}

void Igrac::setPrezime(string prezime) {
	this->prezime = prezime;
}

void Igrac::setBrojDresa(int broj) {
	this->brojDresa = broj;
}

void Igrac::setTrzisnaCijena(double cijena) {
	this->trzisnaCijena = cijena;
}

void Igrac::setTrzisnaCijena(int cijena) {
	this->trzisnaCijena = (double)cijena;
}