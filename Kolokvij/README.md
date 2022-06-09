# Završni kolokvij

Podaci o nalazištu metalnih sirovina sadrže naziv, lokaciju i popis sirovina, dok svaka sirovina ima naziv, količinu
(kg/tjedno) i cijenu (kn/kg).

a) Implementirajte klase `Nalaziste` i `Sirovina` te njihove konstruktore koji trebaju inicijalizirati sve opisane podatkovne
članove osim popisa sirovina (**3 boda**).

b) Implementirajte konstruktor klase `Nalaziste` koji osim naziva i lokacije može primiti i spremiti neograničen broj sirovina.
Implementaciju konstruktora potrebno je napisati van klase. (**3 boda**)

c) U funkciji `main` kreirajte nalazište s barem 2 sirovine (proizvoljni naziv, količina i cijena), te preopterećenjem `operatora <<`
za to nalazište ispišite sve sirovine (svaku u svom retku) sortirane po cijeni (od najmanje prema najvećoj) (**4 boda**) Ukoliko se
prilikom sortiranja za usporedbu podataka koristi lambda funkcija dobije se **dodatni 1 bod**.

d) Prilikom definiranja cijene sirovine potrebno je demonstrirati enkapsulaciju na način da nova cijena sirovine mora biti u rasponu
[3,100] kn/kg. U protivnom je potrebno baciti iznimku tipa `IznimkaCijena` koja metodom `Ispis` ispisuje odgovarajuću poruku korisniku.
U opisu poruke mora se nalaziti podatak o pogrešnoj cijeni. (**3 boda**)

Također, u opisu poruke potrebno je ispisati i redni broj generirane iznimke koji je u početku jednak nuli, a generiranjem svake
nove iznimke ovog tipa povećava se za 1. Primjer prvog ispisa: "Iznimka 1: Cijena od 2.3 kn/kg je pogresna!". Demonstrirati u funkciji
`main`. (**4 boda**)

e) Nalazišta mogu biti glavna i sekundarna. U funkciji `main` kreirajte po jedno nalazište od oba tipa te napišite globalnu funkciju
`double UkupnaCijenaSirovina(const vector<Nalaziste*>& nalaziste)` koja korištenjem polimorfizma vraća ukupnu cijenu sirovina svih 
predanih nalazišta s uključenim transportom. Pri tome, svako glavno nalazište plaća cijenu transporta sirovine 0.4 kn/kg količine
za svaku sirovinu, dok svako sekundarno nalazište plaća transport 0.85 kn/kg količine za svaku sirovinu.
Ukupna cijena nalazišta čini sumu cijene ukupne tjedne količine sirovina i ukupne cijene transporta za tu količinu. (**6 bodova**)

f) Neka se u klasi `TerminalSirovina` nalazi niz sirovina realiziranih pokazivačima na objekte tipa `Sirovina`. Za klasu `TerminalSirovina`
implementirajte:

- prijenosni konstruktor (3 boda)
- operator pridruživanja sa semantikom kopiranja (3 boda)

Klasa `TerminalSirovina` treba sadržavati odgovarajući destruktor. U protivnom se **oduzima 1 bod**.