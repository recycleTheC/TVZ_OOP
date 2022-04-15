# 4. Računi i artikli

Potrebno je napisati program za evidenciju računa.
Primjerice, u dućanu svaki kupac ima račun s jedinstvenim rednim brojem,
a na tom računu se nalazi popis kupljenih stavki (naziv, količina, jedinična cijena).

```cpp
	Kupac Ante(Racun(1)); // Ante ima račun broj 1
	Ante.racun.dodaj(Artikl("Jabuka", 1, 6)); // 1 kg, 6 kn/kg
	Ante.racun.dodaj(Artikl("Banana", 2, 7.5)); // 2 kg, 7.5 kn/kg
	Ante.racun.dodaj(Artikl("Coca cola 2l", 2, 10)); // 2 boce, 10 kn/boca
	cout << "Ukupno: " << Ante.racun.ukupnaCijena << " kn" << endl; // 41 kn

	/* U nastavku ispišite koji je najskuplji artikl kojeg je Ante platio (naziv i ukupna cijena).
	Npr. Najskuplje placeni artikl je Coca cola 2l (20kn)
	*/
```
