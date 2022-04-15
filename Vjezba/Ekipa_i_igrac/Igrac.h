#pragma once

#include<string>

using namespace std;

class Igrac {
private:
	string ime, prezime;
	int brojDresa = 0;
	double trzisnaCijena = 0;

public:
	Igrac();
	Igrac(string ime, string prezime);
	~Igrac();

	string getIme() const;
	string getPrezime() const;
	string ispisi() const;
	int getBrojDresa() const;
	double getTrzisnaCijena() const;

	void setIme(string ime);
	void setPrezime(string prezime);
	void setBrojDresa(int broj);
	void setTrzisnaCijena(double cijena);
	void setTrzisnaCijena(int cijena);
};