#include "Osoba.h"
#include<iostream>

namespace Vjezba3 {
	Osoba::Osoba(string ime, string prezime, int gr) {
		setIme(ime);
		setPrezime(prezime);
		setGodinaRodjenja(gr);
	}

	string Osoba::getIme() const { return ime; }
	string Osoba::getPrezime() const { return prezime; }
	int Osoba::getGodinaRodjenja() const { return godina; }

	string Osoba::normaliziraj(const string ulaz) {
		string tekst = ulaz;

		tekst[0] = toupper(tekst[0]);

		for (int i = 1; i < tekst.size(); i++)
		{
			tekst[i] = tolower(tekst[i]);
		}

		return tekst;
	}

	void Osoba::setIme(string ime) {
		this->ime = normaliziraj(ime);
	}

	void Osoba::setPrezime(string prezime) {
		this->prezime = normaliziraj(prezime);
	}

	void Osoba::setGodinaRodjenja(int godina) {
		if (godina < 1900) {
			cout << "Neispravna godina rodjenja!" << endl;
			exit(1);
		}
		else {
			this->godina = godina;
		}
	}

	void ispisiOsobu(Osoba* o) {
		cout << o->getIme() << " " << o->getPrezime() << ", " << o->getGodinaRodjenja() << "." << endl;
	}
}