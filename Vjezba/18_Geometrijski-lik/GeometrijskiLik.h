#pragma once
#include <string>

using namespace std;

class GeometrijskiLik {
public:
	char Naziv[20 + 1];

	GeometrijskiLik() {
		strcpy_s(Naziv, 21, "Geometrijski lik");
	}

	virtual double Opseg() const = 0;
	virtual double Povrsina() const = 0;
};