# Du�an i dobavlja�i

Svaki du�an ima svoj popis dobavlja�a, a svaki dobavlja� ima naziv (string) i broj (int) te podatak o tome je li strani dobavlja� (bool).

1) U funkciji `main` kreirajte 5 proizvoljnih objekata tipa `Dobavljac`, te na sljede�i na�in ispi�ite koliko je stranih dobavlja�a:
`cout << Dobavljac::brojStranih() << endl;`

2) U klasi `Ducan` implementirajte metodu `Dodaj` koja odabranog dobavlja�a dodaje na popis dobavlja�a tog du�ana. Metoda `Dodaj` mora biti
implementirana tako da podr�ava ulan�ano pozivanje. Demonstrirajte ulan�ani poziv ove metode u funkciji `main`.

3) Implementirajte `operator <<` nad klasom `Ducan` tako da u jednom retku ispisuje naziv i broj svakog dobavlja�a tog du�ana.

4) U klasi `Ducan` implementirajte `operator -=` koji �e ukloniti odabranog dobavlja�a unutar tog du�ana.
Ukoliko se odabrani dobavlja� ne nalazi u popisu dobavlja�a tog du�ana potrebno je baciti iznimku tipa `DobavljacIznimka`. U funkciji
`main` demonstrirajte hvatanje tog tipa iznimke, a prilikom obrade te iznimke potrebno je pozvati njenu metodu `info()` koja ispisuje odgovaraju�u poruku
(npr. "Iznimka: Dobavljac 367001 nije pronadjen!").

5) Implementirajte operator pretvorbe `int` nad klasom `Ducan`. On treba vratiti ukupni broj dobavlja�a du�ana.
Demonstrirajte u funkciji `main`.