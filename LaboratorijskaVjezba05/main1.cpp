#include<iostream>

using namespace std;

class Slika {
private:
	static inline double _zbrojCijena = 0; // C++ 17 standard
	static inline int _instance = 0;
public:
	double cijena = 0;

	Slika(double cijena) {
		this->cijena = cijena;
		_zbrojCijena += cijena;
		_instance++;
	}

	static double ProsjecnaCijena() {
		return _zbrojCijena / _instance;
	}
};

int main() {
	Slika Slika1(2000); // 2000 eura
	Slika Slika2(3000); // 3000 eura
	Slika Slika3(1800); // 1800 eura

	cout << Slika::ProsjecnaCijena() << " eura"; // 2266.67 eura

	return 0;
}