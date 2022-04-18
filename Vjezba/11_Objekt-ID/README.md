# 11. Objekt ID

Napišite klasu Objekt koja interno prati koliko njenih instanci postoji te koji je jedinstveni identifikator (ID) svake instance.
Identifikator je cijeli broj koji počinje od 0 te se za svaku instancu klase Objekt uvećava za 1.
Jednom dodijeljen, ID više ne može biti prenesen na drugi objekt (instancu). Primjerice,

```cpp
#include <iostream>
#include "Objekt.h"

using namespace std;

int main() {
	Objekt obj1; // ID = 1, brojInstanci = 1
	Objekt niz[10]; // ID = 2..11, brojInstanci = 11
	Objekt* p = new Objekt[10]; // ID = 12..21, brojInstanci = 21
	delete[] p; // brojInstanci = 11!
	Objekt zadnji;

	cout << zadnji.ID << " " << Objekt::BrojInstanci() << endl; // 22 12

	return 0;
}
```

Napisana klasa Objekt treba proizvesti efekte koji su opisani u komentarima gornjeg primjera programskog koda.