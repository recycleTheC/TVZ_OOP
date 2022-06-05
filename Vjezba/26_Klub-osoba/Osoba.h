#pragma once

#include<string>

using namespace std;

class Osoba {
private:
	string ime, prezime;
public:
	Osoba(string ime, string prezime) : ime(ime), prezime(prezime) {}

	string getIme() const { return this->ime; }
	string getPrezime() const { return this->prezime; }

	void setIme(string ime) {
		this->ime = ime;
	}

	void setPrezime(string prezime) {
		this->prezime = prezime;
	}

	friend void ispisOsobe(const Osoba& o);
};