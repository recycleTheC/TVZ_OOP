#include<iostream>

using namespace std;

class Kompleksni {
private:
	double re, im;
public:
	Kompleksni(double realni, double imaginarni) : re(realni), im(imaginarni) {}

	Kompleksni operator + (Kompleksni& z) {
		return Kompleksni(this->re + z.re, this->im + z.im);
	}
	
	Kompleksni operator + (double r) {
		return Kompleksni(this->re + r, this->im);
	}

	friend ostream& operator << (ostream& izlaz, const Kompleksni& Z);
};

ostream& operator << (ostream& izlaz, const Kompleksni& Z) {
	izlaz << Z.re << (Z.im > 0 ? "+" : "") << Z.im << "i";
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