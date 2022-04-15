# 3. Evidencija garaža

Pretpostavimo da ste vlasnik niza garaža u kojima spremate razne predmete.
Napišite program za evidenciju garaža tako da za svaku od njih znate koje predmete sadrži.

Klasa Garaza ima sljedeæa svojstva:
- velièinu (širina x duljina)
- podatak o tome jesu li vrata s automatskim upravljanjem ili ne
- lokaciju
- niz predmeta

Klasa Predmet ima sljedeæa svojstva:
- naziv
- vrijednost

U glavnom programu potrebno je od korisnika tražiti unos broja N, nakon kojeg se unose podaci o N garaža.
Nakon što se unesu sva polja, potrebno je tražiti unos broja M koji oznaèava broj predmeta koji se nalaze u garažama.
Uèitajte sve predmete i ispišite sve garaže i predmete koji se u njima nalaze.

## Primjer izvoðenja:

```
Unesite broj garaža (N): 2

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