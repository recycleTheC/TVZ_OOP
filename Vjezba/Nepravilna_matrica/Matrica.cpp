#include "Matrica.h"

Matrica::Matrica() {}

Matrica::~Matrica() {
	for (int i = 0; i < redak.size(); i++)
	{
		delete[] redak[i];
	}
}

Matrica::Matrica(const Matrica& m) {
	// kopirni konstruktor

	for (int i = 0; i < m.redak.size(); i++)
	{
		int n = m.stupac[i];

		redak.push_back(new int[n]);
		stupac.push_back(n);

		for (int j = 0; j < n; j++)
		{
			redak[i][j] = m.redak[i][j];
		}
	}
}

Matrica::Matrica(Matrica&& m) {
	// konstruktor prijenosa

	for (int i = 0; i < m.redak.size(); i++)
	{
		redak.push_back(m.redak[i]);
		m.redak[i] = NULL;

		stupac.push_back(m.stupac[i]);
	}
}

Matrica& Matrica::operator = (const Matrica& m) {
	// operator pridruživanja sa dubokim kopiranjem

	if (this != &m) {

		for (int i = 0; i < redak.size(); i++)
		{
			delete[] redak[i];
		}

		redak.clear();
		stupac.clear();

		for (int i = 0; i < m.redak.size(); i++)
		{
			int n = m.stupac[i];

			redak.push_back(new int[n]);
			stupac.push_back(n);

			for (int j = 0; j < n; j++)
			{
				redak[i][j] = m.redak[i][j];
			}
		}
	}

	return *this;
}

Matrica& Matrica::operator = (Matrica&& m) {
	// operator pridruživanja sa prijenosom

	if (this != &m) {

		for (int i = 0; i < redak.size(); i++)
		{
			delete[] redak[i];
		}

		redak.clear();
		stupac.clear();

		for (int i = 0; i < m.redak.size(); i++)
		{
			redak.push_back(m.redak[i]);
			m.redak[i] = NULL;

			stupac.push_back(m.stupac[i]);
		}
	}

	return *this;
}

void Matrica::dodaj(int brStupaca, int* redak) {
	this->stupac.push_back(brStupaca);
	this->redak.push_back(redak);
}

void Matrica::ispis() {
	for (int i = 0; i < redak.size(); i++)
	{
		for (int j = 0; j < stupac[i]; j++)
		{
			cout << redak[i][j] << " ";
		}

		cout << endl;
	}

	cout << endl;
}