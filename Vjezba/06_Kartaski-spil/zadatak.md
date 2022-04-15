# 6. Karta�ki �pil

U karta�kom �pilu se nalaze 52 karte a svaka od karti je ozna�ena brojem 1-52.
Napi�ite program koji �e za N igra�a (N <= 13) podijeliti po 4 karte iz karta�kog �pila.
Prilikom kreiranja karta�kog �pila sve karte mogu biti poredane po redu (1-52) ili izmije�ane slu�ajnim redoslijedom
(random_shuffle, zaglavlje algorithm).

Na po�etku programa potrebno je unijeti N igra�a te kreirati novi (izmije�ani) �pil karata.
Upotrebom metode `void Spil::Podijeli4Karte(Igrac *igrac)` svakom od igra�a treba podijeliti po 4 karte sa vrha �pila.
Svaki igra� ima svoje ime te popis karti koje su mu podijeljene.
Program treba ispisati karte koje su podijeljene svakom od igra�a a zatim i karte koje su ostale u �pilu.

## Primjer izvo�enja (izmije�ani �pil karata):

Unesi broj igraca: 2
Unesi ime 1.igraca: Ante
Unesi ime 2.igraca: Ivica

Karte u spilu (52):
10 7 5 6 4 41 26 8 31 42
2 33 47 37 14 16 51 35 24 38
18 25 21 36 11 49 52 29 45 13
19 44 43 32 12 3 30 17 34 9
40 22 1 20 27 39 15 46 50 23
48 28

Ante je dobio sljedece karte: 10 7 5 6
Ivica je dobio sljedece karte: 4 41 26 8

Preostale karte u spilu (44):
31 42 2 33 47 37 14 16 51 35 24 38 18 25 21 36 11 49 52 29 45 13 19 44 43 32 12 3 30 17 34 9 40 22 1 20 27 39 15 46 50 23 48 28