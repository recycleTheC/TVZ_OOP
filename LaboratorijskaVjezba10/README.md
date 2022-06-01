# 10. laboratorijska vježba

**Napomena**: na vježbi se rješenja mogu napisati u jednoj .cpp datoteci - moja će biti napisana u zasebnim datoteka zbog preglednosti!

## 1. zadatak

Napišite predložak funkcije koja prima 2 vektora istog tipa koja će zamjeniti njihove elemente.
Funkcija ima povratni tip `void`.

## 2. zadatak

Potrebno je nadopuniti donji programski odsječak na način da napišete funkciju `izdvoji`, za koju vrijedi sljedeće:

- vraća `vector<int>` (novi vektor)
- prvi argument: `vector<int>&`
- drugi argument: `funkcija`

Funkcija izdvoji mora iz vektora "brojevi" izdvojiti samo dvoznamenkaste brojeve. Drugi argument funkcije potrebno je poslati kao lambda izraz (nadopuniti).

```cpp
int main() {

	vector<int> brojevi = { 1, 4, 5, 7, 3, 6, 12, 65, 32, 8, 87, 55, 23, 22, 1, 1, 433, 66, 7, 433, 3, 32, 76, 8, 72, 256, 42 };

	vector<int> rez = izdvoji(brojevi, /*lambda izraz*/);

	for (int i = 0; i < rez.size(); i++)
		cout << rez[i] << " ";
	//ispis: 12 65 32 87 55 23 22 66 32 76 72 42

	return 0;
}
```

## 3. zadatak

Napišite predložak klase `Red` koja ima metodu `Dodaj` za dodavanje elementa na kraj reda, metodu `Brisi` koja uklanja zadnji element
iz reda, te metodu `BrojElemenata` koja vraća broj elemenata koji se nalaze u redu.

## 4. zadatak

Napišite lambda izraz koji će elemente vektora uvećati za vrijednost varijable `increment`. Potrebno je definirati način prijenosa vrijednosti varijabli.

```cpp
int main() {

	vector<int> brojevi = { 1, 4, 5, 7, 3, 6, 12, 65, 32, 8, 87, 55, 23, 22, 1, 1, 433, 66, 7, 433, 3, 32, 76, 8, 72, 256, 42 };

	int increment = 3;

	/* lambda izraz */

	for (int i = 0; i < brojevi.size(); i++)
		cout << brojevi[i] << " ";
	//ispis: 4 7 8 10 6 ...

	return 0;
}
```

## 5. zadatak

Napišite program za pretraživanje studenata tako da radi kako je ispod prikazano.

```cpp
int main() {
	vector<Student> v = { 
		Student("Pero", "Peric", "0246"),
		Student("Ivan", "Ivic", "1357"),
		Student("Ivo", "Ivic", "9013"),
		Student("Ivan", "Juric", "4650")
	};

	// nađi sve studente s imenom Ivan
	vector<Student*> r = nadji(v, [](Student* s) { return s->ime() == "Ivan"; });

	/* Ispisuje
		Ivan Ivic 1357
		Ivan Juric 4650
	*/

	for (Student* s : r) {
		cout << s->ime() << " " << s->prezime() << " " << s->jmbag() << endl;
	}

	return 0;
}
```