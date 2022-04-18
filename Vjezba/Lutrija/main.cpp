#include<iostream>
#include"Lutrija.h"

using namespace std;

int main() {
	int n, max;

	cout << "Koliko brojeva sadrzi kombinacija?: ";
	cin >> n;

	cout << "Maksimalni broj: ";
	cin >> max;

	try
	{
		Lutrija lutrija(max, n);

		int* mojaKombinacija = new int[n];

		for (int i = 0; i < n; i++)
		{
			cout << i + 1 << ": ";
			cin >> mojaKombinacija[i];
		}

		cout << lutrija.dobitnaKombinacija() << endl;
		cout << "Pogodjeno brojeva: " << lutrija.provjeriDobitak(mojaKombinacija) << endl;

	}
	catch (const char* poruka)
	{
		cout << poruka << endl;
	}

	return 0;
}