#include<iostream>

using namespace std;

namespace Osoba {
	class Posao {
	private:
		static inline double _suma = 0; // C++ 17 Standard
		static inline int _brojac = 0;
	public:
		string opis;
		double placa;
		Posao(string opis, double placa) : opis(opis), placa(placa) {
			this->_suma += placa;
			this->_brojac++;
		}
		static double getProsjecnaPlaca() {
			return _suma / (double)_brojac;
		}
	};
}

int main() {

	Osoba::Posao Ante("vozac", 5000);
	Osoba::Posao Ivica("pekar", 4000);
	cout << Osoba::Posao::getProsjecnaPlaca() << endl; // 4500

	return 0;
}