# 9. laboratorijska vježba

## 1. Niz

a) Napišite klasu `Niz` s jednom generičkim parametrom koja se može instancirati na sljedeći način:

```cpp
	vector<int> v1 = {1, 2, 3};
	vector<int> v2 = {11, 0, 13};

	Niz<int> p1(v1);
	Niz<int> p2(v2);
```

b) Klasa `Niz` treba imati metodu `manje_od` s jednim parametrom tipa `const Niz&` koja uspoređuje svoj niz (postavljen kod inicijalizacije)
s nizom u parametru i vraća 1 ako su svi elementi vektora ovog objekta manji od svakog elementa vektora parametra, inače vraća 0.

c) Upotrebom predložaka napišite nečlanski `operator <` tako da taj operator vraća rezultat metode `manje_od` kao rezultat usporedbe. Na primjer:

```cpp
	vector<int> v1 = {1, 2, 3};
	vector<int> v2 = {11, 0, 13};

	Niz<int> p1(v1);
	Niz<int> p2(v2);

	cout << (p1 < p2) << endl;  // operator <
```

d) Upotrebom predložaka napišite `operator >=` koji vraća 1 samo ako operator < vraća 0 za zadane parametre.

e) Napišite klasu `Niz2` koja radi kao klasa Niz, s tim da je `operator <` definiran kao članska funkcija.

## 2. Brojevi s neparnim znamenkama

Potrebno je nadopuniti donji programski odsječak na način da napišete funkciju "izdvoji", za koju vrijedi sljedeće:

- vraća vector<int> (novi vektor)
- prvi argument: vector<int>&
- drugi argument: funkcija

Funkcija izdvoji mora iz vektora "brojevi" izdvojiti samo one brojeve kojima su zadnje dvije znamenke neparne. Drugi argument funkcije potrebno je poslati kao lambda izraz (nadopuniti).

```cpp
int main() {

	vector<int> brojevi = { 1, 4, 5, 7, 3, 6, 12, 65, 32, 8, 87, 55, 23, 22, 1, 1, 433, 66, 7, 433, 3, 32, 76, 8, 72, 256, 42 };

	vector<int> rez = izdvoji(brojevi, /*lambda izraz*/);

	for (int i = 0; i < rez.size(); i++)
		cout << rez[i] << " ";
	//ispis: 55 433 433

	return 0;
}
```

## 3. Komparator

a) Napišite klasu `Komparator` koja ima jedan generički parametar `T` i metodu `vece_ili_jednako` koja ima dva parametra tipa `T` i koja vraća rezultat 
usporedbe tih dvaju parametara operacijom >=.

b) Napišite zaglavlje funkcije `usporedi` koja ima jedan generički parametar `P` koji označava tip elemenata u vektoru. Isto tako, funkcija treba imati dva 
parametra: prvi je vektor s elementima tipa `P` koje uspoređujemo (`vector<P>`), a drugi objekt klase `Komparator` koja radi s elementima tipa `P`(`Komparator<P>`). 

c) Upotrebom objekta tipa `Komparator` i njegove metode `vece_ili_jednako` funkcija `usporedi` treba vratiti 0 ako elementi u vektoru nisu poslagani 
u opadajućem redoslijedu, odnosno 1 ako jesu.

d) Upotreba funkcije "usporedi" treba izgledati ovako:

```cpp
vector<int> v = {12, 2, 1};

bool r = usporedi<int>(v, Komparator<int>());
cout << "rezultat: " << r << endl;  // treba ispisati 1
```

e) Implementirajte metodu `usporedi` tako da radi s bilo kojom klasom koja ima metodu "vece_ili_jednako" povratnog tipa bool, s dva parametra (to jest, ne 
radi samo s klasom Komparator).

## 4. Brojevi djeljivi s rednim brojem u nizu

Potrebno je nadopuniti donji programski odsječak na način da napišete funkciju `izdvoji`, za koju vrijedi sljedeće:

- vraća `vector<int>` (novi vektor)
- prvi argument: `vector<int>&`
- drugi argument: funkcija

Funkcija izdvoji mora iz vektora `brojevi` izdvojiti samo one brojeve koji su djeljivi svojim rednim brojem u nizu (redni brojevi počinju od 1).
Drugi argument funkcije potrebno je poslati kao lambda izraz (nadopuniti).

```cpp
int main() {

	vector<int> brojevi = { 1, 4, 5, 7, 3, 6, 12, 65, 32, 8, 87, 55, 23, 22, 1, 1, 433, 66, 7, 433, 3, 32, 76, 8, 72, 256, 42 };
	vector<int> rez = izdvoji(brojevi, /*lambda izraz*/);

	for (int i = 0; i < rez.size(); i++)
		cout << rez[i] << " ";
	//ispis: 1 4 6

	return 0;
}
```