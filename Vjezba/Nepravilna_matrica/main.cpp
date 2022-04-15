#include<iostream>
#include<vector>
#include"Matrica.h"

using namespace std;

int main() {
	Matrica mat1;

	mat1.dodaj(3, new int[3]{ 1,6,2 }); // dodaj novi redak sa 3 stupca
	mat1.dodaj(5, new int[5]{ 5,3,4,7,0 });
	mat1.dodaj(4, new int[4]{ 6,2,6,5 });

	mat1.ispis();

	Matrica mat2 = mat1; // kopirni konstruktor

	Matrica mat3;
	mat3 = mat2; // operator pridruživanja

	return 0;
}