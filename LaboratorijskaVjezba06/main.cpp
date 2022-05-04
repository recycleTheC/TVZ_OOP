#include<iostream>

using namespace std;

class RGBException {
public:
	const char* poruka() {
		return "Vrijednost komponente boje nije u intervalu [0,255]!";
	}
};

class RGB {
private:
	static inline int _brojac = 0; // C++ 17 Standard
	int red = 0, green = 0, blue = 0;

	bool ispravnost(int v) { return v >= 0 && v <= 255; }
public:
	RGB() = default;
	RGB(int r, int g, int b) : red(r), green(g), blue(b) {
		if (r >= 128 || g >= 128 || b >= 128) {
			_brojac++;
		}
	}

	static int brojac() { return _brojac; }

	void SetRGB(int r, int g, int b);

	friend bool operator == (const RGB& a, const RGB& b);

	RGB operator ++() {
		if (this->red < 255)++this->red;
		if (this->green < 255)++this->green;
		if (this->blue < 255)++this->blue;
		return *this;
	}

	RGB operator ++(int) {
		RGB novi = *this;
		if (this->red < 255) this->red++;
		if (this->green < 255) this->green++;
		if (this->blue < 255) this->blue++;
		return novi;
	}

	friend ostream& operator << (ostream& izlaz, const RGB& boja);
	friend istream& operator >> (istream& ulaz, RGB& boja);
};

void RGB::SetRGB(int r, int g, int b) {
	if (!ispravnost(r) || !ispravnost(g) || !ispravnost(b)) throw RGBException();
	else {
		this->red = r;
		this->green = g;
		this->blue = b;
	}
}

ostream& operator << (ostream& izlaz, const RGB& boja) {
	izlaz << "Boja: " << boja.red << "," << boja.green << "," << boja.blue;
	return izlaz;
}

istream& operator >> (istream& ulaz, RGB& boja) {
	cout << "Upisite vrijednosti boja (R G B): ";
	ulaz >> boja.red >> boja.green >> boja.blue;
	return ulaz;
}

bool operator == (const RGB& a, const RGB& b) {
	return a.red == b.red && a.green == b.green && a.blue == b.blue;
}

int main() {

	RGB boja1(128, 129, 130);
	RGB boja2(255, 255, 255);
	RGB boja3(1, 1, 1);

	cout << RGB::brojac() << endl;

	try {
		boja3.SetRGB(-1, 0, 1);
	}
	catch (RGBException ex) {
		cout << ex.poruka() << endl;
	}

	boja3.SetRGB(255, 255, 255);
	if (boja2 == boja3) cout << "OK" << endl;

	RGB boja4;

	cout << ++boja4 << endl;
	cout << boja4++ << endl;
	cout << boja4 << endl;

	RGB boja5;
	cin >> boja5;
	cout << boja5;

	return 0;
}