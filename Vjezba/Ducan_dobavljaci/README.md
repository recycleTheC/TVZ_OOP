# Duæan i dobavljaèi

Svaki duæan ima svoj popis dobavljaèa, a svaki dobavljaè ima naziv (string) i broj (int) te podatak o tome je li strani dobavljaè (bool).

1) U funkciji `main` kreirajte 5 proizvoljnih objekata tipa `Dobavljac`, te na sljedeæi naèin ispišite koliko je stranih dobavljaèa:
`cout << Dobavljac::brojStranih() << endl;`

2) U klasi `Ducan` implementirajte metodu `Dodaj` koja odabranog dobavljaèa dodaje na popis dobavljaèa tog duæana. Metoda `Dodaj` mora biti
implementirana tako da podržava ulanèano pozivanje. Demonstrirajte ulanèani poziv ove metode u funkciji `main`.

3) Implementirajte `operator <<` nad klasom `Ducan` tako da u jednom retku ispisuje naziv i broj svakog dobavljaèa tog duæana.

4) U klasi `Ducan` implementirajte `operator -=` koji æe ukloniti odabranog dobavljaèa unutar tog duæana.
Ukoliko se odabrani dobavljaè ne nalazi u popisu dobavljaèa tog duæana potrebno je baciti iznimku tipa `DobavljacIznimka`. U funkciji
`main` demonstrirajte hvatanje tog tipa iznimke, a prilikom obrade te iznimke potrebno je pozvati njenu metodu `info()` koja ispisuje odgovarajuæu poruku
(npr. "Iznimka: Dobavljac 367001 nije pronadjen!").

5) Implementirajte operator pretvorbe `int` nad klasom `Ducan`. On treba vratiti ukupni broj dobavljaèa duæana.
Demonstrirajte u funkciji `main`.