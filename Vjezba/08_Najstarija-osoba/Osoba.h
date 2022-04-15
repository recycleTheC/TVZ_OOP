#pragma once

#include<string>
#include<iostream>

using namespace std;

class Osoba {
private:
	string ime, prezime;
	int godinaRodjenja = 1900; // postaviti neku default vrijednost ?!

	string pretvarac(const string& tekst);
public:
	Osoba() = default;
	~Osoba() = default;
	Osoba(string ime, string prezime, int godRodj);

	string getIme() const;
	void setIme(string ime);

	string getPrezime() const;
	void setPrezime(string prezime);

	int getGodinaRodjenja() const;
	void setGodinaRodjenja(int godina);

	string toString() const;
};