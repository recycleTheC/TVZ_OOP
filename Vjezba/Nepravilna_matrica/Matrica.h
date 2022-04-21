#pragma once

#include<vector>
#include<iostream>

using namespace std;

class Matrica {
public:
	vector<int*> redak; // svaki redak matrice je pokazivac na niz
	vector<int> stupac; // broj stupaca za svaki redak matrice

	Matrica();
	~Matrica();
	Matrica(const Matrica& m);
	Matrica(Matrica&& m);
	Matrica& operator = (const Matrica& m);
	Matrica& operator = (Matrica&& m);

	void dodaj(int brStupaca, int* redak);

	void ispis();
};

