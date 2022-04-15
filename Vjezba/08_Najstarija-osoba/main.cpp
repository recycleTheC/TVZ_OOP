#include<iostream>
#include"Osoba.h"

using namespace std;

int main() {
	int n = 5;
	Osoba* osobe = new Osoba[n];

	for (int i = 0; i < n; i++)
	{
		string ime, prezime; int godina;

		cout << "Upisi podatke za " << i + 1 << ". osobu:" << endl;

		cout << "- ime: ";
		cin >> ime;

		cout << "- prezime: ";
		cin >> prezime;

		cout << "- godina rodjenja: ";
		cin >> godina;

		osobe[i] = Osoba(ime, prezime, godina);
	}

	int najstarijaOsoba = 0;

	for (int i = 1; i < n; i++)
	{
		if (osobe[najstarijaOsoba].getGodinaRodjenja() > osobe[i].getGodinaRodjenja()) {
			najstarijaOsoba = i;
		}
	}

	cout << "Najstarija osoba: ";
	cout << osobe[najstarijaOsoba].toString() << endl;

	return 0;
}