#include "GeometrijskiLik.h"

#define PI 3.14

class Krug : public GeometrijskiLik {
public:
	double r;

	Krug(double r) {
		strcpy_s(this->Naziv, "Krug");
		this->r = r;
	}

	double Opseg() const override {
		return 2 * this->r * PI;
	}

	double Povrsina() const override {
		return this->r * this->r * PI;
	}
};