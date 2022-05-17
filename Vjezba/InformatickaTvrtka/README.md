# Informatièka tvrtka

U informatièkoj tvrtki zaposleno je nekoliko tipova zaposlenika, a ovo su njihove karakteristike:
Šefovi - prosjeèna plaæa: 10.000 kn
Programeri - prosjeèna plaèa: 7.000 kn od èega najviše ima visoko-kvalificiranih (VSS) programera sa prosjeènom plaæom od 8.000 kn.

a) Sukladno navedenoj specifikaciji deklarirajte sve potrebne klase i pokažite ispravan model nasljeðivanja.

b) Svaki zaposlenik ima svoje ime a njega se treba inicijalizirati konstruktorom glavne bazne klase koja u konaènici mora biti realizirana kao apstraktna klasa.
U funkciji `main` kreirajte novi objekt tipa `Programer` sa proizvoljnim imenom.

c) Svaki od zaposlenika podrazumijevano ima podatak o lokaciji svog radnog mjesta, a on se vraæa pozivom metode `GetRadnoMjesto`.
Za sve zaposlenike ova metoda podrazumijevano treba vratiti "Unutar tvrtke".
U klasama `Sef` i `Programer` implementirajte nadreðenje (eng. override) te metode tako da vraæaju "Tvrtka - vlastiti ured" za klasu `Sef`
te "Tvrtka - zajednièki ured" za klasu `Programer`. Demonstrirajte pozive nadreðenih metoda u funkciji `main`.

d) Napišite globalnu funkciju:
`double ProsjecnaPlaca(vector<Zaposlenik*> tvrtka);`
koja treba vratiti ukupnu prosjeènu plaæu svih zaposlenika u predanom vektoru. U funkciji `main` testirajte i demonstrirajte poziv ove funkcije tako da u
vektor smjestite adrese barem 3 objekta (zaposlenika) razlièitog tipa. Napomena: u funkciji `ProsjecnaPlaca` potrebno je demonstrirati polimorfizam prilikom
dohvata prosjeène plaæe pojedinog tipa zaposlenika.

e) U funkciji main dodajte sljedeæu pretvorbu na više:
`Zaposlenik* z = new Programer('Ivica');`

Prilikom dealokacije pokazivaèa 'z' potrebno je da se prvo izvrši destruktor klase Programer, a zatim i destruktor klase Zaposlenik. Demonstrirajte u funkciji main.

NAPOMENE:
- Za rješavanje zadatka studenti mogu koristiti Visual Studio
- Studene mogu p sati sav programski kod u istoj (jednoj) datoteci
- Konaèno rješenje potrebno je predati kao tekst (copy/paste programskog koda)