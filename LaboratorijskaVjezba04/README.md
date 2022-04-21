# 4. laboratorijska vježba

Podaci o putničkoj agenciji sadrže naziv, adresu te popis putnika koji putuju u zadanom trenutku. Podatak o putniku sadrži ime, prezime, destinaciju i cijenu putovanja.

a) Deklarirajte klase 'Agencija' i 'Putnik' te njihove članove tako da se pomoću njih može opisati gore navedena specifikacija. Popis putnika u putničkoj agenciji realizirajte pomoću vektora pokazivača na putnike.

b) Unutar klase Putnik demonstrirajte enkapsulaciju tj. implementirajte metode za postavljanje i dohvat cijene putovanja tako da nova vrijednost može biti samo u intervalu [0, 25000]. Ukoliko to pravilo nije zadovoljeno novu vrijednost treba ignorirati.

c) U klasi Agencija implementirajte kopirni konstruktor te demonstrirajte njegov poziv u funkciji main.

d) U klasi Agencija implementirajte prijenosni konstruktor te demonstrirajte njegov poziv u funkciji main.

e) U klasi Agencija implementirajte operator pridruživanja sa semantikom prijenosa te demonstrirajte njegov poziv u funkciji main.

NAPOMENE:
* Klasa Agencija mora imati odgovarajući destruktor. U protivnom gubi se 0,5 bodova.
- Za rješavanje zadatka studenti mogu koristiti Visual Studio
- Studenti mogu pisati sav programski kod u istoj (jednoj) datoteci
- Konačno rješenje potrebno je predati kao tekst (copy/paste programskog koda)