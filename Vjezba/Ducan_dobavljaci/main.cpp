#include<iostream>
#include"Ducan.h"

using namespace std;

int main() {
	Dobavljac dobavljac1("Metro", 1, false);
	Dobavljac dobavljac2("Velpro", 2, false);
	Dobavljac dobavljac3("Kaufland AG", 3, true);
	Dobavljac dobavljac4("Lidl AG", 4, true);
	Dobavljac dobavljac5("Technomarkt", 5, true);

	cout << Dobavljac::brojStranih() << endl;

	Ducan ducan;
	ducan.Dodaj(dobavljac1).Dodaj(dobavljac2).Dodaj(dobavljac3).Dodaj(dobavljac4).Dodaj(dobavljac5);

	try
	{
		ducan -= 2;
		ducan -= 99;
	}
	catch (DobavljacIznimka iznimka)
	{
		cout << iznimka.info() << endl;
	}

	cout << (int)ducan << endl;
	cout << ducan << endl;

	return 0;
}