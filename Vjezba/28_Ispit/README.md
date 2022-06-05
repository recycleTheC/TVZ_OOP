# Primjeri prijašnjih zadataka sa pismenih ispita

1. Napišite program koji u mapi pronalazi najveći datum kako je pokazano u donjem primjeru.
Funkcija `najveci_dan` mora vraćati vrijednost tipa `Datum`.

```cpp
int main() {
	map<string, vector<Datum>> mapa;
	
	mapa["a"] = { Datum(4, 7, 2013), Datum(18, 6, 2015), Datum(20, 7, 2016),
		Datum(20, 7, 2014), Datum(1, 7, 2015)
	};
	mapa["b"] = { Datum(11, 9, 2016), Datum(3, 10, 2016), Datum(4, 10, 2016),
		Datum(30, 10, 2016)
	};
	
	mapa["c"] = { Datum(1, 2, 2012), Datum(7, 2, 2013), Datum(12, 1, 2014),
		Datum(11, 1, 2015)
	};
	// mogu postojati i drugi kljucevi ...

	cout << "Najveci: " << najveci_dan(mapa); // ispisuje 30.10.2016.

	return 0;
}
```

2. Napišite klase `Par` i `Kolekcija`, gdje objekt klase `Kolekcija` sadrži skupinu objekata klase `Par` i omogućava pretraživanje parova kako je ispod pokazano.

```cpp
int main() {

	Par<string, string> dok1("a", "test1");
	Par<string, string> dok2("b", "test2");

	Kolekcija<Par<string, string>> kol_str;

	kol_str.dodaj(dok1);
	kol_str.dodaj(dok2);

	// ispisuje b:test2
	try {
		Par<string, string>* x = kol_str.nadji(Par<string, string>("b", "test2"));
		cout << x->kljuc() << ":" << x->vrijednost() << endl;
	}
	catch (KolekcijaException& e) {
		cout << e.what();
	}
	// ispisuje "trazeni element ne postoji"
	try {
		Par<string, string>* y = kol_str.nadji(Par<string, string>("X", "TEST"));
		cout << y->kljuc() << ":" << y->vrijednost() << endl;
	}
	catch (KolekcijaException& e) {
		cout << e.what();
	}

	return 0;
}
```

3. Definirajte klasu Recenica koja podržava sljedeće operacije, kako je pokazano u kodu ispod:

- Usporedba dvije rečenice operatorom ==
- Nečlanska funkcija "iste_rijeci" koja daje True samo ako dvije rečenice sadrže iste riječi, bez obzira na njihov poredak ili razmake medju riječima
- Konverzija iz tipa Recenica u string
- Nečlanska funkcija "razlika" koja daje broj riječi u kojima se dvije rečenice razlikuju.

```cpp
int main() {

	Recenica r1("ne znam koliko je sati");
	Recenica r2("sutra je praznik");
	Recenica r3("koliko je sati ne znam");
	Recenica r4("ne znam koliko je sati");
	Recenica r5("sutra je slavlje");

	// ispisuje "sutra je praznik"
	string recenica = r2;
	cout << recenica << endl;

	// ispisuje "recenice imaju iste rijeci"
	if (iste_rijeci(r4, r3)) {
		cout << "recenice imaju iste rijeci\n";
	}
	else {
		cout << "recenice nemaju iste rijeci\n";
	}

	// ispisuje "nisu iste recenice"
	if (r1 == r2) {
		cout << "iste recenice\n";
	}
	else {
		cout << "nisu iste recenice\n";
	}

	// ispisuje 0
	double razlika1 = razlika(r1, r4);
	cout << razlika1 << endl;

	//// ispisuje 6
	double razlika2 = razlika(r1, r2);
	cout << razlika2 << endl;

	//// ispisuje 2
	double razlika3 = razlika(r2, r5);
	cout << razlika3 << endl;

	return 0;
}
```