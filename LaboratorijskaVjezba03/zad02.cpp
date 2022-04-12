#include <iostream>
#include <string>

using namespace std;

class Zrno {
public:
	string boja;
	float promjer;
};

class Pijesak {
public:
	int kolicina;
	Zrno* zrno;

	Pijesak(int _kolicina) : kolicina(_kolicina) {
		zrno = new Zrno[kolicina];
	}

	~Pijesak() {
		delete[] zrno;
	}

	Pijesak& operator = (const Pijesak& p) {
		// operator pridruzivanja & duboko kopiranje
		if (this != &p) {
			delete[] zrno;

			kolicina = p.kolicina;
			zrno = new Zrno[kolicina];

			for (int i = 0; i < kolicina; i++)
			{
				zrno[i] = p.zrno[i];
			}
		}

		return *this;
	}

	Pijesak& operator = (Pijesak&& p) {
		// operator pridruzivanja & prijenos
		if (this != &p) {
			delete[] zrno;

			kolicina = p.kolicina;
			zrno = p.zrno;
			p.zrno = NULL;
		}

		return *this;
	}

	Pijesak(const Pijesak& p) {
		// kopirni konstruktor

		kolicina = p.kolicina;
		zrno = new Zrno[kolicina];

		for (int i = 0; i < kolicina; i++)
		{
			zrno[i] = p.zrno[i];
		}
	}

	Pijesak(Pijesak&& p) {
		// konstruktor prijenosa

		kolicina = p.kolicina;
		zrno = p.zrno;
		p.zrno = NULL;
	}
};

int main() {

	// preporuka: rezultate provjeriti u debuggeru!

	Pijesak igraliste(1000000);
	igraliste.zrno[0].promjer = 1;

	Pijesak skola = igraliste; // kopirni konstruktor
	skola.zrno[0].promjer = 2;
	
	Pijesak vrtic(0);
	vrtic = skola;  // operator = (copy)
	vrtic.zrno[0].promjer = 3;
	
	Pijesak skola2 = move(Pijesak(500000)); // konstruktor prijenosa
	skola2.zrno[0].promjer = 4;
	
	Pijesak skola3(0);
	skola3 = Pijesak(500000); // operator = (move)
	skola3.zrno[0].promjer = 5;
	
	return 0;
}