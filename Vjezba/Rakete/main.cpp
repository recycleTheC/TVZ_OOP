#include <iostream>
#include <string>
#include "Raketa.h"

using namespace std;

int main() {
	string nazivRakete;
	double domet;
	cout << "Unesi naziv rakete i domet:" << endl;
	cin >> nazivRakete >> domet;

	Raketa r1(nazivRakete, domet);

	string imeGrada, imeDrzave;
	cout << "Grad proizvodnje - Unesi ime grada i ime drzave:" << endl;
	cin >> imeGrada >> imeDrzave;

	Grad* g = new Grad(imeGrada, imeDrzave);
	r1.setGradProizvodnje(*g);

	int brCiljeva;
	cout << "Unesi broj ciljeva:" << endl;
	cin >> brCiljeva;

	while (brCiljeva--)
	{
		cout << "Novi cilj - Unesi ime grada i ime drzave:" << endl;
		cin >> imeGrada >> imeDrzave;

		Grad* g = new Grad(imeGrada, imeDrzave);
		r1.dodajCilj(g);
	}

	//Kod za testiranje kopirnog konstruktora i operatora pridruživanja

	r1.dodajCilj(new Grad("Testni grad 1", "Nigdjezemska"));

	Raketa r2 = r1;
	r2.dodajCilj(new Grad("Testni grad 2", "Nigdjezemska"));

	Raketa r3(r1);
	r3.dodajCilj(new Grad("Testni grad 3", "Nigdjezemska"));

	cout << "\nCiljevi 1:" << endl;

	for (int i = 0; i < r1.ukCiljeva(); i++)
	{
		Grad* cilj = r1.dohvatiCilj(i);
		cout << i+1 << ": " << cilj->getNaziv() << ", " << cilj->getDrzava() << endl;
	}

	cout << "\nCiljevi 2:" << endl;

	for (int i = 0; i < r2.ukCiljeva(); i++)
	{
		Grad* cilj = r2.dohvatiCilj(i);
		cout << i + 1 << ": " << cilj->getNaziv() << ", " << cilj->getDrzava() << endl;
	}

	cout << "\nCiljevi 3:" << endl;

	for (int i = 0; i < r3.ukCiljeva(); i++)
	{
		Grad* cilj = r3.dohvatiCilj(i);
		cout << i + 1 << ": " << cilj->getNaziv() << ", " << cilj->getDrzava() << endl;
	}

	cout << endl;

	return 0;
}