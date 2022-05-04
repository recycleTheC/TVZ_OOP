#pragma once

#include<iostream>

using namespace std;

class Dobavljac {
private:
	static inline int _strani_dobavljaci = 0; // C++ 17 Standard
	string naziv;
	int broj = 0;
	bool strani = false;
public:
	Dobavljac() = default;
	Dobavljac(string ime, int id, bool tip);

	static int brojStranih();

	string getNaziv() const;
	int getBroj() const;
	bool getStrani() const;
};