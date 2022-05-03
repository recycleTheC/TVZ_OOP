# Igra i igrači

Svaka igra ima svoj popis igrača, a svaki igrač ima ID (string), te podatak o tome je li igrač početnik (bool).

1) U funkciji `main` kreirajte 5 proizvoljnih objekata tipa `Igrac`, te na sljedeći način ispišite koliko njih su početnici:
```cpp
cout << Igrac::brojPocetnika() << endl;
```

2) U klasi `Igra` implementirajte metodu `Dodaj` koja odabranog igrača dodaje na popis sudionike te igre. Metoda `Dodaj` mora biti implementirana tako
da podržava ulančano pozivanje. Demonstirajte ulančani poziv ove metode u funkciji `main`.

3) Implementirajte `operator <<` nad klasom `Igra` tako da u jednom retku ispisuje ID svakog igrača te igre.

4) U klasi `Igra` implementirajte `operator +=` koji će odabranog igrača dodati u popis igrača. Ukoliko se odabrani igrač već nalazi u popisu
sudionika igre potrebno je baciti izniku tipa `IgracIznimka`. U funkciji `main` demonstrirajte hvatanje tog tipa iznimke, a prilikom obrade te iznimke
potrebno je pozvati njenu metodu `poruka()` koja ispisuje odgovarajuću poruku, npr. "Igrac 12345 je vec na popisu!".

5) Implementirajte operator pretvorbe `int` nad klasom `Igra`. On treba vratiti koliko igrača sudjeluje u odabranoj igri.
Demonstrirajte u funkciji `main`.