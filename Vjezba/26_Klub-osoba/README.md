# 26. Klub i osoba (1. parcijalni kolokvij)

Potrebno je napraviti klase `Klub` i `Osoba`. `Klub` ima obilježja naziv, adresa i trener (pokazivač na objekt tipa `Osoba`).
`Osoba` ima ime i prezime.

- Razdvojiti implementaciju klase `Klub` na `.h` i `.cpp` datoteku.
- Napisati get i set metode u klasi `Osoba` za atribute ime i prezime.
- Definirati potrebna `const` ograničenja.
- Napisati funkciju za dohvat trenera imajući na umu da se pri dohvatu ne smije stvoriti novi objekt tipa `Osoba`.
- Napisati konstruktor klase `Osoba` s prototipom `Osoba(string ime, string prezime)`. Nije dopušteno mijenjati imena argumenata.
- Napisati destruktor klase `Klub`.
- Napisati kopirni konstruktor i operator pridruživanja za klasu `Klub`.
- Napisati `friend` funkciju za ispis podataka o osobi oblika `void ispisOsobe(const Osoba& o)`.
- U `main` programu stvoriti dinamički objekt tipa `Klub k1` i dinamički objekt tipa `Osoba o1`. Definirati da je `o1` trener kluba `k1`.
- Stvoriti objekt k2 iz objekta k1 koristeći kopirni konstruktor.
- Promjeniti podatke o treneru kluba `k2` i ispisati podatke o oba kluba.