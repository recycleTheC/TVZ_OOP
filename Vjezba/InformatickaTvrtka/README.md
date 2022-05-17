# Informati�ka tvrtka

U informati�koj tvrtki zaposleno je nekoliko tipova zaposlenika, a ovo su njihove karakteristike:
�efovi - prosje�na pla�a: 10.000 kn
Programeri - prosje�na pla�a: 7.000 kn od �ega najvi�e ima visoko-kvalificiranih (VSS) programera sa prosje�nom pla�om od 8.000 kn.

a) Sukladno navedenoj specifikaciji deklarirajte sve potrebne klase i poka�ite ispravan model naslje�ivanja.

b) Svaki zaposlenik ima svoje ime a njega se treba inicijalizirati konstruktorom glavne bazne klase koja u kona�nici mora biti realizirana kao apstraktna klasa.
U funkciji `main` kreirajte novi objekt tipa `Programer` sa proizvoljnim imenom.

c) Svaki od zaposlenika podrazumijevano ima podatak o lokaciji svog radnog mjesta, a on se vra�a pozivom metode `GetRadnoMjesto`.
Za sve zaposlenike ova metoda podrazumijevano treba vratiti "Unutar tvrtke".
U klasama `Sef` i `Programer` implementirajte nadre�enje (eng. override) te metode tako da vra�aju "Tvrtka - vlastiti ured" za klasu `Sef`
te "Tvrtka - zajedni�ki ured" za klasu `Programer`. Demonstrirajte pozive nadre�enih metoda u funkciji `main`.

d) Napi�ite globalnu funkciju:
`double ProsjecnaPlaca(vector<Zaposlenik*> tvrtka);`
koja treba vratiti ukupnu prosje�nu pla�u svih zaposlenika u predanom vektoru. U funkciji `main` testirajte i demonstrirajte poziv ove funkcije tako da u
vektor smjestite adrese barem 3 objekta (zaposlenika) razli�itog tipa. Napomena: u funkciji `ProsjecnaPlaca` potrebno je demonstrirati polimorfizam prilikom
dohvata prosje�ne pla�e pojedinog tipa zaposlenika.

e) U funkciji main dodajte sljede�u pretvorbu na vi�e:
`Zaposlenik* z = new Programer('Ivica');`

Prilikom dealokacije pokaziva�a 'z' potrebno je da se prvo izvr�i destruktor klase Programer, a zatim i destruktor klase Zaposlenik. Demonstrirajte u funkciji main.

NAPOMENE:
- Za rje�avanje zadatka studenti mogu koristiti Visual Studio
- Studene mogu p sati sav programski kod u istoj (jednoj) datoteci
- Kona�no rje�enje potrebno je predati kao tekst (copy/paste programskog koda)