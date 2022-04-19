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

	Kompleksni& operator ++() {
		// prefiks
		++re;
		++im;
		return *this;
	}

	Kompleksni operator ++(int) {
		// sufiks
		Kompleksni tmp = *this;
		re++;
		im++;
		return tmp;
	}

	operator double() {
		return re;
	}
};

Kompleksni operator + (double br, Kompleksni z) {
	//return Kompleksni(z.re + br, z.im);
	return z + br;
}

ostream& operator << (ostream& ispis, const Kompleksni& z) {
	ispis << z.re << (z.im < 0 ? "" : "+") << z.im << "i";
	return ispis;
}

istream& operator >> (istream& ulaz, Kompleksni& z) {
	ulaz >> z.re >> z.im;
	return ulaz;
}

int main() {
	Kompleksni A(1, 2);

	cout << A << endl; // 1 2
	cout << (double)A << endl;

	return 0;
}