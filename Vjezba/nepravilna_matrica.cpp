#include<iostream>
#include<vector>

using namespace std;

class Matrica {
public:
	vector<int*> redak; // svaki redak matrice je pokazivac na niz
	vector<int> stupac; // broj stupaca za svaki redak matrice

	Matrica() {}
	~Matrica() {
		for (int i = 0; i < redak.size(); i++)
		{
			delete[] redak[i];
		}
	}

	Matrica(const Matrica& m) {
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

	Matrica(Matrica&& m) {
		// konstruktor prijenosa

		for (int i = 0; i < m.redak.size(); i++)
		{
			redak.push_back(m.redak[i]);
			m.redak[i] = NULL;

			stupac.push_back(m.stupac[i]);
		}
	}

	Matrica& operator = (const Matrica& m) {
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

	Matrica& operator = (Matrica&& m) {
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

	void dodaj(int brStupaca, int* redak) {
		this->stupac.push_back(brStupaca);
		this->redak.push_back(redak);
	}

	void ispis() {
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
};

int main() {
	Matrica mat1;

	mat1.dodaj(3, new int[3]{ 1,6,2 }); // dodaj novi redak sa 3 stupca
	mat1.dodaj(5, new int[5]{ 5,3,4,7,0 });
	mat1.dodaj(4, new int[4]{ 6,2,6,5 });

	mat1.ispis();

	Matrica mat2 = mat1; // kopirni konstruktor
	
	Matrica mat3;
	mat3 = mat2; // operator pridruživanja

	return 0;
}