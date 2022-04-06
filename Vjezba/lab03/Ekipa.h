#pragma once

#include"Igrac.h"
#include<iostream>
#include<string>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Ekipa {
private:
	string naziv;
	vector<Igrac> igraci;
public:
	Ekipa();
	~Ekipa();

	string getNaziv() const;

	Igrac& getIgrac(int i);
	Igrac& getNajskuplji();

	void ispisi();

	double ukupnaCijena() const;
	double prosjecnaCijena() const;

	void dodajIgraca(Igrac igrac);
	void setNaziv(string naziv);
};

