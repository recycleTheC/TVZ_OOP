#include<iostream>
#include "Student.h"

using namespace std;

int BrojStudenata(Student* p, int elem, int semestar) {
	int n = 0;

	for (int i = 0; i < elem; i++)
		if (p[i].semestar == semestar) n++;

	return n;
}

int main() {

	Student GrupaA[5] = {
		Student("12345678"),
		Student("91234567"),
		Student("89012345"),
		Student("67890123"),
		Student("45678901")
	};

	cout << "Broj studenata 1. semestra: " << BrojStudenata(GrupaA, 5, 1);

	return 0;
}