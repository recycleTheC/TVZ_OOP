#include<iostream>

using namespace std;

class Kompleksni {
public:
	double re, im;
	Kompleksni() = default;
	Kompleksni(double _re, double _im) : re(_re), im(_im) {}

	Kompleksni operator + (Kompleksni z) {
		// lijevi operator se podrazumijeva da je tipa Kompleksni
		return Kompleksni(re + z.re, im + z.im);
	}
	Kompleksni operator + (double br) {
		// lijevi operator se podrazumijeva da je tipa Kompleksni
		return Kompleksni(re + br, im);
	}
};

Kompleksni operator + (double br, Kompleksni z) {
	//return Kompleksni(z.re + br, z.im);
	return z + br;
}

int main() {
	Kompleksni A(1, 1), B(2, -2), C;

	C = A + B;
	cout << C.re << " " << C.im << "i" << endl;

	C = C + 2.5;
	cout << C.re << " " << C.im << "i" << endl;

	C = 2.5 + C;
	cout << C.re << " " << C.im << "i" << endl;

}