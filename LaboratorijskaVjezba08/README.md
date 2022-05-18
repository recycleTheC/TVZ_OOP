# 8. laboratorijska vježba

U dućanu s igračkama se prodaje nekoliko tipova/vrsta igrački, a ovo su njihove karakteristike:

- Autić  - prosječna cijena: 12 kn
- Kocka - prosječna cijena:  45 kn, od čega se najviše prodaju pod-vrsta kocaka Lego: prosječne cijene 100 kn.

a) Sukladno navedenoj specifikaciji deklarirajte sve potrebne klase i prikažite ispravan model nasljeđivanja.

b) Svaka igračka ima svoj naziv, a njega se treba inicijalizirati konstruktorom glavne bazne klase koja u konačnici mora biti realizirana kao apstraktna klasa.
U funkciji `main` kreirajte novi objekt tipa `Kocka` sa proizvoljnim nazivom.

c) Svaka igračka podrazumijevano ima podatak o materijalu izrade, a on se vraća pozivom metode `GetMatIzrade`.
Za sve igračke ova metoda podrazumijevano treba vratiti "mijesani materijali". U klasama `Autic` i `Kocka` implementirajte nadređenje (eng. override) te
metode tako da vraćaju "metal i plastika" za klasu `Autic` te "plastika" za klasu `Kocka`. Demonstrirajte pozive nadređenih metoda u funkciji `main`.

d) Napišite globalnu funkciju
`double ProsjecnaCijena(vector<Igracka*> ducan);`    
 koja treba vratiti ukupnu prosječnu cijenu svih igrački u predanom vektoru. U funkciji `main` testirajte i demonstrirajte poziv ove funkcije tako da
 u vektor smjestite adrese barem 3 objekta (igračka) različitog tipa. Napomena: u funkciji `ProsjecnaCijena` potrebno je demonstrirati polimorfizam prilikom
 dohvata prosječne cijene pojedinog tipa/vrste igračke.
    
e) U funkciji `main` dodajte sljedeću pretvorbu na više:
  `Igracka* ig = new Autic("BMW");`
    
   Prilikom dealokacije pokazivača `ig` potrebno je da se prvo izvrši destruktor klase `Autic`, a zatim i destruktor klase `Igracka`.
   Demonstrirajte u funkciji `main`.

 
NAPOMENE:
- Za rješavanje zadatka studenti mogu koristiti Visual Studio
- Studenti mogu pisati sav programski kod u istoj (jednoj) datoteci
- Konačno rješenje potrebno je predati kao tekst (copy/paste programskog koda)