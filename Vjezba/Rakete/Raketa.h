#pragma once

#include <string>
#include <vector>
#include "Grad.h"

using namespace std;

class Raketa {
private:
	string naziv;
	double domet;
	Grad* gradProizvodnje;
	vector<Grad*> ciljevi;
public:
	Raketa(void);
	Raketa(string naziv, double domet);
	Raketa(const Raketa& other);
	~Raketa(void);
	Raketa& operator=(const Raketa& other);
	Raketa& operator=(Raketa&& other);

	void setGradProizvodnje(Grad& grad);
	Grad* getGradProizvodnje();

	void dodajCilj(Grad* grad);
	Grad* dohvatiCilj(int index);

	int ukCiljeva();
};