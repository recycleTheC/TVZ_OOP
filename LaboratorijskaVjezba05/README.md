# Laboratorijska vježba 5

## 1. zadatak

Sva slika ima svoju cijenu izraženu u eurima.
Slijedeći programski kod u nastavku napišite klasu Slika i sve potrebne podatkovne članove i metode kojima se dobije očekivano ponašanje programskog koda.

```cpp
Slika Slika1(2000); // 2000 eura
Slika Slika2(3000); // 3000 eura
Slika Slika3(1800); // 1800 eura

cout << Slika::ProsjecnaCijena() << " eura"; // 2266.67 eura
```

## 2. zadatak

Potrebno je napraviti klasu Cigla, te omogućiti lijepljenje jedne cigle na drugu pomoću operatora +=.
Cigla koja se lijepi se stavlja na plohu istih dimenzija, te joj se treća dimenzija automatski povećava.
Cigla se s vremenom može pohabati, pa je i to potrebno omogućiti operatorom -- (svaka dimenzija joj se smanjuje za 1 prilikom habanja).

**Opaska autora koda**: u tekstu zadatka nije navedeno što se treba dogoditi kada se cigla do kraja istroši!

```cpp
int main()
{
	Cigla a(1, 2, 3); // 1, 2 i 3 su duljine bridova cigle. Cigla je kvadar
	Cigla b(2, 3, 4);
	a += b; // Lijepimo ciglu b na plohu 2x3 (cigle se lijepe na plohu istih dimenzija), i dobivamo ukupno ciglu veličine 5x2x3

	cout << a; // 5 x 2 x 3
	a += Cigla(3, 5, 1);
	cout << a; // 5 x 3 x 3
	a += Cigla(3, 3, 2);
	cout << a; // 7 x 3 x 3

	a--;
	a--;
	cout << a; // 5 x 1 x 1

	return 0;
}
```