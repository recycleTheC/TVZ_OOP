#include "GeometrijskiLik.h"

class Kvadrat : public GeometrijskiLik {
public:
	double a;

	Kvadrat(double a) {
		strcpy_s(this->Naziv, 21, "Kvadrat");
		this->a = a;
	}

	double Opseg() const override {
		return 4 * a;
	}

	double Povrsina() const override {
		return a * a;
	}
};