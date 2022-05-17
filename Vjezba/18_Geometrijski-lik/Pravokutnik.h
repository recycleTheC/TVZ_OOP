#include "GeometrijskiLik.h"

class Pravokutnik : public GeometrijskiLik {
public:
	double a, b;

	Pravokutnik(double a, double b) {
		strcpy_s(this->Naziv, 21, "Pravokutnik");
		this->a = a;
		this->b = b;
	}

	double Opseg() const override {
		return 2 * (a + b);
	}

	double Povrsina() const override {
		return a * b;
	}
};