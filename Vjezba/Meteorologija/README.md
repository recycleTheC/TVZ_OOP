# Meteorologija

Vodite evidenciju o meteorološkim postajama i za svaku postaju koja ima neki `redni broj` i `lokaciju`
zapisujete `brzinu vjetra`, `temperaturu`, `vlažnost` i `tlak` za taj dan.

Zanima vas koje postaje su zabilježile manje temperature od prosjeka svih zabilježenih temperatura,
a zatim morate ispisati koje od tih postaja imaju najveću izmjerenu vrijednost tlaka zraka

## Primjeri izvršanja:

[!] Lokacija će uvijek sadržavati samo 1 riječ!

1.
```
Ulaz:

3
1 Zagreb 2 15 75 101820
5 Krapina 1 12 96 101800
6 Hvar 3 19 62 101950

Izlaz:

1 Zagreb 2 15 75 101820 
5 Krapina 1 12 96 101800 

Najvisi tlak:
1 Zagreb 2 15 75 101820 
```

2.
```
Ulaz:

6
5 Krapina 1 12 96 101800
14 Pula 7 18 79 101700 
7 Umag 3 17 62 102010
12 Koprivnica 1 9 97 101800
21 Split 7 18 74 101640
39 Gospic 7 4 100 82650

Izlaz:

5 Krapina 1 12 96 101800 
12 Koprivnica 1 9 97 101800 
39 Gospic 7 4 100 82650 

Najvisi tlak:
5 Krapina 1 12 96 101800 
12 Koprivnica 1 9 97 101800 
```