#pragma once

#include<vector>
#include "Dobavljac.h"
#include "DobavljacIznimka.h"

class Ducan {
private:
	vector<Dobavljac> dobavljaci;

public:
	Ducan() = default;

	Ducan& Dodaj(Dobavljac d);
	friend ostream& operator << (ostream& izlaz, const Ducan& d);

	void operator -= (const int id);
	operator int();
};