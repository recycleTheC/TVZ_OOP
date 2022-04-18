# Rakete

Prijatelj vas je zamolio da mu pomognete napraviti program kojim æe se voditi
evidencija o raketama koje jedna zemlja posjeduje. Pošto oni planiraju napraviti puno raketa, logièno je
da poènete prvo od klase Raketa i njenog kopirnog konstruktora (da bi bilo moguæe kopirati što više
raketa èim prije).

Vaš zadatak je napraviti klasu Raketa, dok main program i klasa Grad veæ postoji u sustavu:

## Grad.h

```cpp
#pragma once

#include <string>
using namespace std;

class Grad {
private:
	string naziv;
	string drzava;
public:
	
	Grad(void){}
	Grad(string naziv, string drzava) :naziv(naziv), drzava(drzava){}

	string getNaziv()
	{
		return naziv;
	}

	void setNaziv(string naziv)
	{
		this->naziv = naziv;
	}
	
	string getDrzava()
	{
		return drzava;
	}
	
	void setDrzava(string drzava)
	{
		this->drzava = drzava;
	}
};
```

## Main.cpp

```cpp
string nazivRakete;
double domet;
cout << "Unesi naziv rakete i domet:" << endl;
cin >> nazivRakete >> domet;
Raketa r(nazivRakete, domet);
string imeGrada, imeDrzave;
cout << "Grad proizvodnje - Unesi ime grada i ime drzave:" << endl;
cin >> imeGrada >> imeDrzave;
Grad* g = new Grad(imeGrada, imeDrzave);
r.setGradProizvodnje(*g);
int brCiljeva;
cout << "Unesi broj ciljeva:" << endl;
cin >> brCiljeva;
while (brCiljeva--)
{
	cout << "Novi cilj - Unesi ime grada i ime drzave:" << endl;
	cin >> imeGrada >> imeDrzave;
	Grad* g = new Grad(imeGrada, imeDrzave);
	r.dodajCilj(g);
}
//Kod za testiranje kopirnog konstruktora i operatora pridruživanja
```

## Raketa.h

```cpp
#pragma once

#include <string>
#include <vector>
#include "Grad.h"

using namespace std;

class Raketa {
private:
	string naziv;
	double domet;
	Grad* gradProizvodnje;
	vector<Grad*> ciljevi;
public:
	Raketa(void);
	Raketa(string naziv, double domet);
	Raketa(const Raketa& other);
	~Raketa(void);
	Raketa& operator=(const Raketa& other);

	void setGradProizvodnje(Grad& grad);
	Grad* getGradProizvodnje();

	void dodajCilj(Grad* grad);
	Grad* dohvatiCilj(int index);

	int ukCiljeva();
};
```

Potrebno je napraviti implementaciju klase Raketa (raketa.cpp). Na sljedeæe stvari treba
paziti prilikom rješavanja:

- Potrebno je implementirati kopirni konstruktor i operator pridruživanja. Prije nego se
riješenje pošalje na sustav, dobro je provjeriti radi li na vlastitom raèunalu (kod za to student
treba smisliti sam)
- Obratiti pozornost na implementaciju destruktora klase Raketa - naime, treba na ispravan
naèin osloboditi memoriju za grad proizvodnje i ciljeve
- Funkcije getGradProizvodnje i dohvatiCilj vraæaju pokazivaè na klasu Grad - pripaziti da
prilikom vraæanja vrijednosti ne nastane "viška" objekata
- funkcija ukCiljeva ima za zadatak samo vratiti ukupan broj ciljeva koje raketa može pogoditi

## Primjer ulaznih podataka

```
V-9000 700
Taedong Pyongyang
4
Seoul S.Korea
Moskva Rusija
Zagreb Hrvatska
Karlovac Hrvatsk
```

### Dodatna pomoæ pri rješavanju

- Pri kreiranju kopirnog konstruktora/operatora pridruživanja potrebno je proæi po svim
ciljevima i napraviti posebnu kopiju za svaki grad koji predstavlja jedan cilj i dodati pokazivaè
na novostvoreni grad u vektor "ciljevi".
- Kod implementacije destruktora proæi po svim ciljevima i pozvati "delete" za svaki
- Koristiti debugger za pronalazak greški