# 3. Evidencija gara�a

Pretpostavimo da ste vlasnik niza gara�a u kojima spremate razne predmete.
Napi�ite program za evidenciju gara�a tako da za svaku od njih znate koje predmete sadr�i.

Klasa Garaza ima sljede�a svojstva:
- veli�inu (�irina x duljina)
- podatak o tome jesu li vrata s automatskim upravljanjem ili ne
- lokaciju
- niz predmeta

Klasa Predmet ima sljede�a svojstva:
- naziv
- vrijednost

U glavnom programu potrebno je od korisnika tra�iti unos broja N, nakon kojeg se unose podaci o N gara�a.
Nakon �to se unesu sva polja, potrebno je tra�iti unos broja M koji ozna�ava broj predmeta koji se nalaze u gara�ama.
U�itajte sve predmete i ispi�ite sve gara�e i predmete koji se u njima nalaze.

## Primjer izvo�enja:

```
Unesite broj gara�a (N): 2

Unesite velicinu, lokaciju i podatak o vratima za 1. garazu:
10 20
Konavoska 3
DA

Unesite velicinu, lokaciju i podatak o vratima za 2. garazu:
15 25
Konavoska 3b
NE

Unesite broj predmeta (M): 1
Unesite redni broj garaze u koju spada 1. predmet: 2
Unesite naziv i vrijednost predmeta: Lopta 400

Ispis garaza i predmeta:
1. Konavoska 3 10x20 - predmeti: 
2. Konavoska 3b 15x25 - predmeti: Lopta (400kn)
```