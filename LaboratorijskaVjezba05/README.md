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

## 3. zadatak

Napravite klasu TimeSpan koja mjeri protok vremena u satima, minutama i sekundama.
Dodajte potrebne operatore (+, --) kako bi kod funkcionirao prema očekivanju.

```cpp
int main(){
	
	TimeSpan a(1, 0, 0);
	a = a + 10;
	cout << a;  //1:0:10
	a = 65 + a;
	cout << a; //1:1:15

	for (int i = 0; i < 60 * 60 + 74; i++)
		a--;

	cout << a; //0:0:1

	a--;
	a--;

	cout << a; //0:0:0

	return 0;
}
```

## 4. zadatak

Definirajte klasu Tekst koja predstavlja tekstualni tip podatka (kao string), s
tim da podrzava operacije *, - i +:
- operacija * umnozava tekst. Na primjer, ako je x = "abc" onda x * 3 daje novi
objekt tipa Tekst koji sadrzi tekst "abcabcabc". Ova operacija mora raditi i
kada je broj s lijeve strane, to jest x * 3 treba davati isti rezultat kao i
3 * x
- operacija - uklanja zadani znak iz teksta. Na primjer, ako je x = "uvala"
onda x - 'a' daje novi objekt tipa Tekst koji sadrzi tekst "uvl", to jest
bez slova 'a'
- operacija + spaja dva teksta u jedan novi tekst. Na primjer, ako je x = "ab"
i y = "cd", onda x + y daje novi objekt tipa Tekst koji sadrzi tekst "abcd"
- treba redefinirati i operator << da radi s objektima tipa Tekst

Ovu klasu treba definirati tako da funkcija main radi kako je ispod prikazano.

```cpp
int main() {
    Tekst t = "abc";
    Tekst p = t * 3;                // "umnozavanje" teksta
    cout << p << endl;                // ispisuje abcabcabc
    cout << 2 * t << endl;            // ispisuje abcabc

    // t mora ostati nepromijenjen!!!
    cout << t << endl;                // ispisuje abc

    cout << t + p << endl;            // ispisuje abcabcabcabc
    cout << t + p - 'a' << endl;    // ispisuje bcbcbcbc

    // p i t moraju ostati nepromijenjeni!!!
    cout << p << endl;                // ispisuje abcabcabc
    cout << t << endl;                // ispisuje abc
}
```

## 5. zadatak

Potrebno je napisati klasu Bubble sa svojstvima boja i radijus.
Implementacijom operatora zbrajanja (+) potrebno je omogućiti "spajanje" dva bubble-a u jedan.
Novi bubble ima obujam jednak zbroju obujama bubble-a od kojih je nastao, a preuzima boju većeg bubble-a.
Pri izdvajanju novog bubble-a iz postojećeg (operator -) nastaje novi sa smanjenim obujmom. Boja ostaje od originalnog bubble-a.

Obujam se računa prema obujmu kugle - V = 4/3 * r * r * r * PI. Također, treći korjen se računa kao pow(x, 1.0/3) (potrebno pri izračunavanju radijusa iz obujma).

Potrebno je dodati i operator == koji uspoređuje dva Bubble objekta. Dva bubble-a su isti ako imaju istu boju, i ako im se radijus razlikuje za ne više od 0.0001.

```cpp
int main() {
	Bubble a("blue", 10.4);
	Bubble b("red", 7.2);
	Bubble c("green", 18.8);

	Bubble x = a + b; //nastat će novi bubble obujma 6275.27
	cout << x; //blue: 11.44
	Bubble y = x + c;
	cout << y; //green: 20.12

	Bubble z = y - x;
	cout << z; //green: 18.8

	if (z == c)
		cout << "OK" << endl; //OK

	return 0;
}
```

## 6. zadatak

Napravite klasu TimeSpan koja mjeri protok vremena u satima, minutama i sekundama.
Dodajte potrebne operatore (+, <, ==, pretvorba) kako bi kod funkcionirao prema očekivanju.

Očekivani ispis:
```
11:6:7
11:43:21
12:20:35
21:32:32
30:44:29
Ukupno sekundi: 110669
```

```cpp
int main() {
	TimeSpan a(1, 0, 0);
	TimeSpan x(24, 0, 0);

	while (a < x)
	{
		if (a == TimeSpan(1, 0, 0))
			a = a + TimeSpan(10, 6, 7);
		else if (a < TimeSpan(12, 0, 0))
			a = a + TimeSpan(0, 37, 14);
		else
			a = a + TimeSpan(9, 11, 57);

		cout << a;

	}

	cout << "Ukupno sekundi: " << (int)a << endl;

	return 0;
}
```