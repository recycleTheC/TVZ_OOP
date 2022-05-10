#include<iostream>
#include<vector>

using namespace std;

class CiglaUnistenaIznimka {
public:
	const char* what() const {
		return "Cigla je unistena!";
	}
};

class CigleRazlicitihPlohaIznimka {
public:
	const char* what() const {
		return "Cigle nemaju iste plohe!";
	}
};

class Cigla {
private:
	vector<double> dimenzije;
public:
	Cigla() {
		this->dimenzije.reserve(3);
	};
	Cigla(double x, double y, double z) {
		if (x > 0) this->dimenzije.push_back(x);
		else this->dimenzije.push_back(0);

		if (y > 0) this->dimenzije.push_back(y);
		else this->dimenzije.push_back(0);

		if (z > 0) this->dimenzije.push_back(z);
		else this->dimenzije.push_back(0);
	}

	void operator += (Cigla& cigla) throw(CigleRazlicitihPlohaIznimka) {

		int dodajNaDimenziju = -1, uzmiSaDimenzije = -1, zajedniceDimenzije = 0;

		for (int i = 0; i < 3; i++)
		{
			int promasaj = 0, odabir = -1;

			for (int j = 0; j < 3; j++)
			{
				if (this->dimenzije[i] != cigla.dimenzije[j]) {
					promasaj++;
					odabir = j;
				}
			}

			if (promasaj == 3) {
				dodajNaDimenziju = i;
				uzmiSaDimenzije = odabir;
			}
			else zajedniceDimenzije++;
		}

		if (dodajNaDimenziju == -1 || uzmiSaDimenzije == -1 || zajedniceDimenzije < 2) throw CigleRazlicitihPlohaIznimka();
		else this->dimenzije[dodajNaDimenziju] += cigla.dimenzije[uzmiSaDimenzije];
	}

	void postaviDimenzije(double x, double y, double z) {
		this->dimenzije.clear();

		if (x > 0) this->dimenzije.push_back(x);
		else this->dimenzije.push_back(0);

		if (y > 0) this->dimenzije.push_back(y);
		else this->dimenzije.push_back(0);

		if (z > 0) this->dimenzije.push_back(z);
		else this->dimenzije.push_back(0);
	}

	void operator += (Cigla&& cigla) {
		int dodajNaDimenziju = -1, uzmiSaDimenzije = -1;

		for (int i = 0; i < 3; i++)
		{
			int promasaj = 0, odabir = -1;

			for (int j = 0; j < 3; j++)
			{
				if (this->dimenzije[i] != cigla.dimenzije[j]) {
					promasaj++;
					odabir = j;
				}
			}

			if (promasaj == 3) {
				dodajNaDimenziju = i;
				uzmiSaDimenzije = odabir;
			}
		}

		if (dodajNaDimenziju == -1 || uzmiSaDimenzije == -1) cout << "Cigle nemaju iste plohe!" << endl;
		else this->dimenzije[dodajNaDimenziju] += cigla.dimenzije[uzmiSaDimenzije];
	}

	Cigla operator -- (int) throw(CiglaUnistenaIznimka) {

		Cigla nova = *this;

		for (int i = 0; i < 3; i++)
		{
			if (this->dimenzije[i] - 1 > 0) this->dimenzije[i]--;
			else throw CiglaUnistenaIznimka();
		}

		return nova;
	}

	friend ostream& operator << (ostream& izlaz, Cigla& cigla);
};

ostream& operator << (ostream& izlaz, Cigla& cigla) {
	izlaz << cigla.dimenzije[0] << " x " << cigla.dimenzije[1] << " x " << cigla.dimenzije[2] << endl;
	return izlaz;
}

int main()
{
	Cigla a(1, 2, 3); // 1, 2 i 3 su duljine bridova cigle. Cigla je kvadar
	Cigla b(2, 3, 4);

	try {
		a += b; // Lijepimo ciglu b na plohu 2x3 (cigle se lijepe na plohu istih dimenzija), i dobivamo ukupno ciglu velièine 5x2x3

		cout << a; // 5 x 2 x 3
		a += Cigla(3, 5, 1);
		cout << a; // 5 x 3 x 3
		a += Cigla(3, 3, 2);
		cout << a; // 7 x 3 x 3

		a--;
		a--;
		cout << a; // 5 x 1 x 1

		a--;
		cout << a;
	}
	catch (const CiglaUnistenaIznimka& iznimka) {
		cout << iznimka.what() << endl;
	}
	catch (const CigleRazlicitihPlohaIznimka& iznimka) {
		cout << iznimka.what() << endl;
	}

	return 0;
}