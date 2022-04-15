# 4. Raèuni i artikli

Potrebno je napisati program za evidenciju raèuna.
Primjerice, u duæanu svaki kupac ima raèun s jedinstvenim rednim brojem,
a na tom raèunu se nalazi popis kupljenih stavki (naziv, kolièina, jedinièna cijena).

```cpp
	Kupac Ante(Racun(1)); // Ante ima raèun broj 1
	Ante.racun.dodaj(Artikl("Jabuka", 1, 6)); // 1 kg, 6 kn/kg
	Ante.racun.dodaj(Artikl("Banana", 2, 7.5)); // 2 kg, 7.5 kn/kg
	Ante.racun.dodaj(Artikl("Coca cola 2l", 2, 10)); // 2 boce, 10 kn/boca
	cout << "Ukupno: " << Ante.racun.ukupnaCijena << " kn" << endl; // 41 kn

	/* U nastavku ispišite koji je najskuplji artikl kojeg je Ante platio (naziv i ukupna cijena).
	Npr. Najskuplje placeni artikl je Coca cola 2l (20kn)
	*/
```