# Igra i igraèi

Svaka igra ima svoj popis igraèa, a svaki igraè ima ID (string), te podatak o tome je li igraè poèetnik (bool).

1) U funkciji `main` kreirajte 5 proizvoljnih objekata tipa `Igrac`, te na sljedeæi naèin ispišite koliko njih su poèetnici:
```cpp
cout << Igrac::brojPocetnika() << endl;
```

2) U klasi `Igra` implementirajte metodu `Dodaj` koja odabranog igraèa dodaje na popis sudionike te igre. Metoda `Dodaj` mora biti implementirana tako
da podržava ulanèano pozivanje. Demonstirajte ulanèani poziv ove metode u funkciji `main`.

3) Implementirajte `operator <<` nad klasom `Igra` tako da u jednom retku ispisuje ID svakog igraèa te igre.

4) U klasi `Igra` implementirajte `operator +=` koji æe odabranog igraèa dodati u popis igraèa. Ukoliko se odabrani igraè veæ nalazi u popisu
sudionika igre potrebno je baciti izniku tipa `IgracIznimka`. U funkciji `main` demonstrirajte hvatanje tog tipa iznimke, a prilikom obrade te iznimke
potrebno je pozvati njenu metodu `poruka()` koja ispisuje odgovarajuæu poruku, npr. "Igrac 12345 je vec na popisu!".

5) Implementirajte operator pretvorbe `int` nad klasom `Igra`. On treba vratiti koliko igraèa sudjeluje u odabranoj igri.
Demonstrirajte u funkciji `main`.