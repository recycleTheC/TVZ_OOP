#pragma once

#include "Osoba.h"

class Student : public Osoba {
public:
	string naziv_studija, smjer;
	int semestar = 1;

	Student(string oib);
	void RadniStatus() const override;
};

