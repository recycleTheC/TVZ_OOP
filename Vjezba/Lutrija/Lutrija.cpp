#include "Lutrija.h"

void Lutrija::generirajBrojeve() {
	if (brojevi != NULL) delete[] brojevi;
	else brojevi = new int[max];

	for (int i = 0; i < max; i++)
	{
		brojevi[i] = i + 1;
	}

	promjesaj();
}

void Lutrija::promjesaj() {
	srand(time(NULL));

	for (int i = 0; i < max; i++)
	{
		int index = rand() % max;

		swap(brojevi[i], brojevi[index]);
	}

	generirajKombinaciju();
	sortiraj(kombinacija, n);
}

void Lutrija::sortiraj(int* polje, int n) {
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (polje[i] > polje[j])
				swap(polje[i], polje[j]);
		}
	}
}

Lutrija::Lutrija(int max, int n) {

	if (max < n || max < 0 || n < 0) throw "Neispravna inicijalizacija!";

	this->max = max;
	this->n = n;
	generirajBrojeve();
	generirajKombinaciju();
	sortiraj(kombinacija, n);
}

Lutrija::~Lutrija() {
	delete[] brojevi;
	delete[] kombinacija;
}

int Lutrija::provjeriDobitak(int* odabrana) const {
	int pogodak = 0;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (kombinacija[i] == odabrana[j]) {
				pogodak++;
				break;
			}
		}
	}

	return pogodak;
}

string Lutrija::dobitnaKombinacija() const {
	string tekst = "Dobitna kombinacija: ";

	for (int i = 0; i < n; i++)
	{
		if (i != 0) tekst += ", ";
		tekst += to_string(kombinacija[i]);
	}

	return tekst;
}

void Lutrija::generirajKombinaciju() {
	if (kombinacija == NULL) kombinacija = new int[n];

	for (int i = 0; i < n; i++)
	{
		kombinacija[i] = brojevi[i];
	}
}