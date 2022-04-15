# Nepravilna matrica

Nepravilna matrica se sastoji od redaka koji nemaju nužno uvijek isti broj stupaca.
Napišite tijela metoda klase Matrica èija deklaracija izgleda na sljedeæi narèin:

```cpp
class Matrica {
public:
	vector<int*> redak; // svaki redak matrice je pokazivac na niz
	vector<int> stupac; // broj stupaca za svaki redak matrice

	Matrica();
	~Matrica();
	Matrica(const Matrica& m);
	Matrica(Matrica&& m);
	Matrica& operator = (const Matrica& m);

	Matrica& operator = (Matrica&& m);

	void dodaj(int brStupaca, int* redak);

	void ispis();
};
```

Matrica se formira na naèin da se metodom `dodaj` matrici preda novo-alocirani 1D niz brojeva:

```cpp
Matrica mat1;

mat1.dodaj(3, new int[3]{ 1,6,2 }); // dodaj novi redak sa 3 stupca
mat1.dodaj(5, new int[5]{ 5,3,4,7,0 });
mat1.dodaj(4, new int[4]{ 6,2,6,5 });

mat1.ispis();
```

Deklaraciju klase `Matrica` spremite u `Matrica.h`, a implementaciju njenih medota u `Matrica.cpp` datoteku.
U funkciji `main` takoðer demonstrirajte poziv kopirnog konstruktora i operatora priduživanja sa semantikom kopiranja.