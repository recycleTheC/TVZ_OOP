#include<iostream>
#include<vector>

using namespace std;

class Kompleksni {
public:
	double re, im;
	Kompleksni(double re, double im) : re(re), im(im) {}

	Kompleksni& operator ++() {
		// prefiksalni operator
		++this->re;
		++this->im;
		return *this;
	}

	Kompleksni operator ++(int) {
		// postfiks operator
		Kompleksni tmp = *this;
		this->re++;
		this->im++;
		return tmp;
	}

	Kompleksni operator * (Kompleksni z) {
		return Kompleksni(this->re * z.re - this->im + z.im, this->re * z.im + z.re * this->im);
	}
};

ostream& operator << (ostream& izlaz, const Kompleksni& z) {
	izlaz << z.re << (z.im > 0 ? "+" : "") << z.im << "i";
	return izlaz;
}

int main() {

	Kompleksni Z1(1, -1), Z2(2, 2);  // Z1.re = 1, Z1.im = -1;   Z2.re = 2, Z2.im = 2
	Kompleksni Z3 = ++Z1 * Z2;       // Z3. re = 4, Z3.im = 4i;
	cout << Z1 << " " << Z3 << endl; // 2 + 0i  4 + 4i

	return 0;
}