#include<iostream>
#include"Slika.h"

using namespace std;

int main() {
	Slika Slika1(2000); // 2000 eura
	Slika Slika2(3000); // 3000 eura
	Slika Slika3(1800); // 1800 eura
	cout << Slika::ProsjecnaCijena() << " eura"; // 2266.67 eura
}