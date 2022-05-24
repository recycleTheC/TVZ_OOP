# 21. Generički kontejner

Napišite vlastiti generički kontejner (predložak klase) koji predstavlja polje podataka generičkog tipa. Broj elemenata tog polja se određuje
konstruktorom klase, a klasa za svaku instancu (polje) mora omogućiti informaciju o broju elemenata, direktan pristup svakom elementu preko
operatora [], te pretragu pojedine vrijednosti u polju.

## Primjer korištenja

```cpp
Polje<int> A(100);

// inicijalizacija elemenata slučajnim vrijednostima 1-100
srand((unsigned)time(NULL));
for (int i = 0; i < 100; i++)
	A[i] = rand() % 100 + 1; // A.polje[i] ...

// ispiši broj elemenata
cout << "Polje ima " << A.BrElem << " elemenata " << endl;

// nalazi li se u polju broj x?
int x = 58;
int indeks = A.Sadrzi(x);

if (indeks != -1) cout << "Broj " << x << " se nalazi u elementu s indeksom " << indeks << "!\n";
else cout << "Broj " << x << " se ne nalazi u polju!\n";
```

**Komentar autora koda**: ovdje nije uzeto u obzir načelo enkapsulacije, što nije dobro! 