#include<iostream>
#include<vector>

using namespace std;

struct Ucenik {
	string ime, prezime;
};
class Razred {
public:
	vector<Ucenik*> ucenik;
	float prosjecnaOcjena = 0; // u tekstu zadatka nije definirano sto treba s varijablom

	Razred() = default;

	Razred(const Razred& razred) {
		for (int i = 0; i < razred.ucenik.size(); i++) {
			this->ucenik.push_back(new Ucenik(*razred.ucenik[i]));
		}

		this->prosjecnaOcjena = razred.prosjecnaOcjena;
	}

	Razred& operator = (const Razred& razred) {
		if (this != &razred) {
			for (int i = 0; i < this->ucenik.size(); i++) {
				delete ucenik[i];
			}
			this->ucenik.clear();

			for (int i = 0; i < razred.ucenik.size(); i++)
			{
				this->ucenik.push_back(new Ucenik(*razred.ucenik[i]));
			}

			this->prosjecnaOcjena = razred.prosjecnaOcjena;
		}

		return *this;
	}

	~Razred() {
		for (int i = 0; i < this->ucenik.size(); i++)
			delete ucenik[i];
		this->ucenik.clear();
	}
};


int main() {

	Razred A;
	Razred B = A;
	B = A;

	Razred C = Razred(); // prijenosni konstruktor
	C = Razred(); // operator = sa sematnikom prijenosa

	return 0;
}