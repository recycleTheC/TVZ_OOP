# 3. laboratorijska vježba

## 1. Knjižnica

Napraviti klasu `Knjiznica` sa sljedećim (privatnim) poljima:

- adresa
- naziv
- kategorija (djecja, znanstvena, ...)

Omogućiti korisniku kreiranje nove knjiznice i postavljanje članova. Treba pripaziti na sljedeća pravila:

- Kategorija moze biti samo "djecja", "znanstvena", "citaonica", "opcenito"
- Naziv mora pocinjati velikim slovom
- Sve provjere pravila je potrebno napraviti unutar klase `Knjiznica`. (Gdje?)

Dodati klasu `Knjiga` s nekoliko proizvoljnih polja (autor, naslov, ISBN, ...).
Neka klasa `Knjiga` ima samo jedan konstruktor, unutar kojeg je potrebno ispisati „Knjiga constructor called“ korisniku,
te jedan destruktor u kojem treba ispisati "Knjiga destructor called" korisniku.

Proširiti klasu Knjiznica s poljem `vector<Knjiga>` i dodati u klasu Knjiznica metode:

- `dodajKnjigu1(Knjiga z)`
- `dodajKnjigu2(Knjiga& z)`
- `dodajKnjigu3(Knjiga* z)` 

Što se ispisuje prilikom poziva metoda 1,2 i 3? U kojim slučajevima se stvara novi objekt?
Zašto se ispisuje više puta destruktor nego konstruktor?

Dodati u klasu Knjiznica metodu `ispisSvihKnjiga`.

Dodati u klasu Knjiznica metode:

- `Knjiga nadjiKnjigu1(string isbn)`
- `Knjiga* nadjiKnjigu2(string isbn)`
- `Knjiga& nadjiKnjigu3(string isbn)`

Koristeći nadjiKnjigu1 naći i zatim izmjeniti podatke o jednoj knjizi, a zatim koristeći metodu nadjiKnjigu2 naći i zatim izmjeniti podatke o drugoj knjizi, te koristeći metodu nadjiKnjigu3 naći i zatim izmjeniti podatke o trećoj knjizi.
Pozvati „ispisSvihKnjiga“ za knjižnicu. Što zapažate?

Koje su prednosti a koji nedostaci u načinima pozivanja metoda s objektima kao parametrima i vraćanja objekata kao vrijednosti iz funkcije?
Kada koristiti jedan način a kada drugi?

## 2. Pijesak

Za klasu `Pijesak` napišite konstruktore i operatore pridruživanja s semantikom kopiranja i semantikom prijenosa.
U funkciji main demonstrirajte njihove pozive.

```cpp
#include <iostream>
#include <string>

using namespace std;

class Zrno{
public:
       string boja;
       float promjer;
};

class Pijesak{
public:
       int kolicina;
       Zrno* zrno;

       Pijesak(int _kolicina) : kolicina(_kolicina){
             // dinamički alocirajte polje 'zrno'
       }

       ~Pijesak(){
             // ?
       }
};

int main(){

       Pijesak igraliste(1000000);
       cout << "Na igralistu ima " << igraliste.kolicina << " zrna pijeska!\n";

       // Demonstrirajte pozive oba konstruktora i oba operatora pridruživanja

       return 0;
}
```