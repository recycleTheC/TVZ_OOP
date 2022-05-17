#include "Student.h"

Student::Student(string oib) : Osoba(oib) {}

void Student::RadniStatus() const {
	cout << "Redovni student" << endl;
}