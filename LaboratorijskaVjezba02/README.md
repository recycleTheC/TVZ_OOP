# 2. laboratorijska vježba

a) napisati klasu Student (ime, prezime, položeni predmeti) i klasa Predmet (naziv, šifra, ocjena)

b) prema zadanom primjeru napraviti konstruktor koji prima ime, prezime i jedan predmet
```cpp
int main() {
	Predmet Matematika(1260, "Matematika", 5); // zadani primjer
	Student Ivica("Ivica", "Ivic", Matematika);

	return 0;
}
```
c) napisati metodu Sortiraj u klasi Student koja će sortirati predmete po ocjeni (od najveće do najmanje)

d) deklarirati metodu Odlicni u klasi Student koja vraća niz predmeta iz kojih student ima 5 i implementirati metodu izvan klase

e) globalna metoda NajboljiStudent koja prima niz studenata i mora vratiti onog koji ima najveći prosjek ocjena.
