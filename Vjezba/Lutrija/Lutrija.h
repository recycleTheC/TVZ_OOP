#pragma once

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class Lutrija {
private:
	int* brojevi = NULL;
	int* kombinacija = NULL;
	int n = 0, max = 0;

	void generirajBrojeve();
	void sortiraj(int* polje, int n);

public:
	Lutrija(int max, int n);
	~Lutrija();

	void promjesaj();
	int provjeriDobitak(int* odabrana) const;
	string dobitnaKombinacija() const;
	void generirajKombinaciju();
};

