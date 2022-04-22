#include <iostream>
#include "Kompleksni.h"

using namespace std;

ostream& operator << (ostream& izlaz, const Kompleksni& Z) {
	izlaz << Z.re << ((Z.im >= 0) ? "+" : "") << Z.im << "i";
	return izlaz;
}

int main() {
	// Z1 = 1, Z2 = 2 - i
	Kompleksni Z1(1, 0), Z2(2, -1);

	// �lanska operatorska funkcija + (Kompleksni)
	Kompleksni Suma = Z1 + Z2;
	cout << Suma << endl; // 3 - 1i

	// �lanska operatorska funkcija *(Kompleksni)
	Kompleksni Umnozak = Z1 * Z2;
	cout << Umnozak << endl; // 2 - 1i

	// ne-�lanska operatorska funkcija - (Kompleksni, double) 
	Kompleksni Razlika = Suma - 3;
	cout << Razlika << endl; // 0 - 1i

	// ne-�lanska operatorska funkcija - (double, Kompleksni)
	Kompleksni Razlika2 = 3 - Suma;
	cout << Razlika2 << endl; // 0 - 1i

	// �lanska operatorska funkcija ++ - prefiks i postfiks
	cout << ++Z1 << endl; // 2 + 1i
	cout << Z1++ << endl; // 2 + 1i
	cout << Z1 << endl; // 3 + 2i
	
	return 0;
}