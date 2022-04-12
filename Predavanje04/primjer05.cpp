#include<iostream>

using namespace std;

int main() {
	double a, b, c;
	cout << "Unesite dva broja: ";
	cin >> a >> b;

	try {
		if (b == 0)
			throw "b je jednak nuli!";
		c = a / b;
		cout << "a/b = " << c;
	}
	catch (const char* Iznimka) {
		cout << "Iznimka: " << Iznimka;
	}
}