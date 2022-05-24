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

	Kompleksni operator + (int a) {
		return Kompleksni(this->re + a, this->im);
	}
};

ostream& operator << (ostream& izlaz, const Kompleksni& z) {
	izlaz << z.re << (z.im > 0 ? "+" : "") << z.im << "i";
	return izlaz;
}

class Matematika {
public:
	template<class T1, class T2>
	auto suma(T1 a, T2 b) {
		return a + b;
	}
};

int main() {

	Matematika Racun;
	cout << Racun.suma(2, 4.3) << endl; // 6.3
	cout << Racun.suma(2.3, 4) << endl; // 6.3
	cout << Racun.suma(Kompleksni(2.5, 1), 4) << endl; // 6.5 1i
	return 0;
}