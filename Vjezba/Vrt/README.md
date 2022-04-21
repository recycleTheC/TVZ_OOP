# Vrt i cvijeće

Unutar imenskog prostora `Hortikultura` napraviti klasu 
`Vrt` sa sljedećim, privatnim poljima:


- adresa
- vlasnik
- sirina
- duljina

Omogućiti korisniku kreiranje novog vrta i postavljanje članova. Treba pripaziti na sljedeća
pravila:
- Povrsina mora biti barem 10m2
- Naziv vlasnika mora pocinjati velikim slovom

Sve provjere pravila je potrebno napraviti unutar klase Vrt.

Unutar imenskog prostora `Hortikultura` dodati klasu `Cvijet` s nekoliko proizvoljnih polja (vrsta, boja, kolicina, ...).
Neka klasa `Cvijet` ima samo jedan konstruktor, unutar kojeg je potrebno ispisati „Cvijet constructor called“
korisniku, te jedan destruktor u kojem treba ispisati "Cvijet destructor called" korisniku. 

Proširiti klasu `Vrt` s poljem `vector<Cvijet*>` i dodati u klasu `Vrt` metode:

- dodajCvijet(Cvijet& z)
- dodajCvijet(Cvijet&& z)
- dodajCvijet(Cvijet* z)

- ispisSvihCvijetova

- Cvijet* nadjiCvijet(string vrsta)

U `main` funkciji demonstrirati korištenje svih metoda.

U klasi `Vrt` implementirati semantike kopiranja i prijenosa te ih demonstrirati.