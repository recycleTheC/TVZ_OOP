#include<iostream>
#include<vector>

using namespace std;

class Slika {
public:
	double cijena;

	static inline double ukupnaCijena = 0;
	static inline int n = 0;

	Slika(double iznos) : cijena(iznos) {
		ukupnaCijena += iznos;
		n++;
	}

	static double ProsjecnaCijena() {
		return ukupnaCijena / n;
	}
};

//Slika::ukupnaCijena = 0;

int main() {
	Slika Slika1(2000); // 2000 eura
	Slika Slika2(3000); // 3000 eura
	Slika Slika3(1800); // 1800 eura
	
	cout << Slika::ProsjecnaCijena() << " eura"; // 2266.67 eura

	return 0;
}
