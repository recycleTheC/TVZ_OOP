#include<iostream>
#include<vector>
#include <string>

using namespace std;

struct Ucenik {
	string ime, prezime;
};

class Razred {
private:
	void dealocirajUcenike() {
		for (int i = 0; i < ucenik.size(); i++)
		{
			if (ucenik[i] != NULL) delete ucenik[i];
		}

		ucenik.clear();
	}
public:
	vector<Ucenik*> ucenik;
	float prosjecnaOcjena = 0;

	Razred() {}
	Razred(vector<Ucenik*>& ucenici) {
		for (int i = 0; i < ucenici.size(); i++)
		{
			this->ucenik.push_back(new Ucenik(*ucenici[i]));
		}
	}
	~Razred() {
		dealocirajUcenike();
	}

	Razred& operator = (Razred&& r) { // operator prijenosa

		this->prosjecnaOcjena = r.prosjecnaOcjena;
		this->dealocirajUcenike();

		for (int i = 0; i < r.ucenik.size(); i++)
		{
			ucenik.push_back(r.ucenik[i]);
			r.ucenik[i] = NULL;
		}

		r.ucenik.clear();

		return *this;
	}

	Razred& operator = (Razred& r) { // operator kopiranja

		if (this != &r) {
			this->prosjecnaOcjena = r.prosjecnaOcjena;
			this->dealocirajUcenike();

			for (int i = 0; i < r.ucenik.size(); i++)
			{
				ucenik.push_back(new Ucenik(*r.ucenik[i]));
			}
		}

		return *this;
	}

	Razred(const Razred& r) { // kopirni konstruktor

		this->prosjecnaOcjena = r.prosjecnaOcjena;
		this->dealocirajUcenike();

		for (int i = 0; i < r.ucenik.size(); i++)
		{
			ucenik.push_back(new Ucenik(*r.ucenik[i]));
		}
	}

	Razred(Razred&& r) { // kopirni konstruktor s prijenosom

		this->prosjecnaOcjena = r.prosjecnaOcjena;
		this->dealocirajUcenike();

		for (int i = 0; i < r.ucenik.size(); i++)
		{
			ucenik.push_back(r.ucenik[i]);
			r.ucenik[i] = NULL;
		}

		r.ucenik.clear();
	}
};

int main() {
	vector<Ucenik*> ucenici;

	for (int i = 0; i < 3; i++)
	{
		ucenici.push_back(new Ucenik);
		ucenici[i]->ime = "Ucenik " + to_string(i + 1);
	}

	Razred razred1(ucenici);
	razred1.ucenik[0]->ime = "Ucenik A";

	Razred razred2(razred1);
	razred2.ucenik[0]->ime = "Ucenik B";

	Razred razred3;
	razred3 = razred2;
	razred3.ucenik[0]->ime = "Ucenik C";

	Razred razred4 = move(Razred(ucenici));
	razred4.ucenik[0]->ime = "Ucenik D";

	Razred razred5;
	razred5 = Razred(ucenici);
	razred5.ucenik[0]->ime = "Ucenik E";

	return 0;
}