#include<iostream>
#include <vector>
#include "Osoba.h"

using namespace std;
using namespace Vjezba3;

int main() {
	
	int n = 0;

	cout << "Upisi broj osoba: ";
	cin >> n;

	vector<Osoba> osobe;

	for (int i = 0; i < n; i++)
	{
		string ime, prezime; int godina;

		cout << "Upisi ime, prezime i godinu rodjenja " << i + 1 << ". osobe: ";
		cin >> ime >> prezime >> godina;

		osobe.push_back(Osoba(ime, prezime, godina));
	}

	Osoba najstarija = osobe[0];

	for (int i = 0; i < osobe.size(); i++)
	{
		if (osobe[i].getGodinaRodjenja() < najstarija.getGodinaRodjenja()) {
			najstarija = osobe[i];
		}
	}

	cout << "Najstarija osoba: ";
	ispisiOsobu(&najstarija);

	return 0;
}