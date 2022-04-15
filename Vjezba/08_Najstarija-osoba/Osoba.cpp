#include "Osoba.h"

string Osoba::pretvarac(const string& tekst) {
	string pretvoreni = tekst;
	pretvoreni[0] = toupper(pretvoreni[0]);

	for (int i = 1; i < pretvoreni.size(); i++)
	{
		pretvoreni[i] = tolower(pretvoreni[i]);
	}
	return pretvoreni;
}

Osoba::Osoba(string ime, string prezime, int godRodj) {
	setIme(ime);
	setPrezime(prezime);
	setGodinaRodjenja(godRodj);
}

string Osoba::getIme() const {
	return ime;
}

void Osoba::setIme(string ime) {
	this->ime = pretvarac(ime);
}

string Osoba::getPrezime() const {
	return prezime;
}

void Osoba::setPrezime(string prezime) {
	this->prezime = pretvarac(prezime);
}

int Osoba::getGodinaRodjenja() const {
	return godinaRodjenja;
}

void Osoba::setGodinaRodjenja(int godina) {
	if (godina >= 1900) {
		this->godinaRodjenja = godina;
	}
	else {
		cout << "Neispravna godina rodjenja!\n";
	}
}

string Osoba::toString() const {
	return ime + " " + prezime + " (" + to_string(godinaRodjenja) + ")";
}