# Igra i igra�i

Svaka igra ima svoj popis igra�a, a svaki igra� ima ID (string), te podatak o tome je li igra� po�etnik (bool).

1) U funkciji `main` kreirajte 5 proizvoljnih objekata tipa `Igrac`, te na sljede�i na�in ispi�ite koliko njih su po�etnici:
```cpp
cout << Igrac::brojPocetnika() << endl;
```

2) U klasi `Igra` implementirajte metodu `Dodaj` koja odabranog igra�a dodaje na popis sudionike te igre. Metoda `Dodaj` mora biti implementirana tako
da podr�ava ulan�ano pozivanje. Demonstirajte ulan�ani poziv ove metode u funkciji `main`.

3) Implementirajte `operator <<` nad klasom `Igra` tako da u jednom retku ispisuje ID svakog igra�a te igre.

4) U klasi `Igra` implementirajte `operator +=` koji �e odabranog igra�a dodati u popis igra�a. Ukoliko se odabrani igra� ve� nalazi u popisu
sudionika igre potrebno je baciti izniku tipa `IgracIznimka`. U funkciji `main` demonstrirajte hvatanje tog tipa iznimke, a prilikom obrade te iznimke
potrebno je pozvati njenu metodu `poruka()` koja ispisuje odgovaraju�u poruku, npr. "Igrac 12345 je vec na popisu!".

5) Implementirajte operator pretvorbe `int` nad klasom `Igra`. On treba vratiti koliko igra�a sudjeluje u odabranoj igri.
Demonstrirajte u funkciji `main`.