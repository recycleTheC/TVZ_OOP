# 1. Kompleksni broj

Napišite program koji u dinamički alocirano polje učitava N kompleksnih brojeva te ih ispisuje 
sortirane po vrijednosti njihovih modula (od najmanjeg prema najvećem).

- Kompleksni broj treba predstaviti klasom Kompleksni koja sadrži realni i imaginarni dio (realni brojevi).
- Modul kompleksnog broja je udaljenost kompleksnog broja od ishodišta i treba se računati globalnom funkcijom Modul.
- Za sortiranje kompleksnih brojeva napišite funkciju Sortiraj koja će sortirati kompleksne brojeve upotrebom BubbleSort algoritma.

## Primjer izvođenja

```
Unesi N: 3
niz[0].re = 3
niz[0].im = -1
niz[1].re = 1
niz[1].im = 1
niz[2].re = 2
niz[2].im = -3
Z(1+1i) Modul: 1.41421
Z(3-1i) Modul: 3.16228
Z(2-3i) Modul: 3.60555
```

Nakon što ste zadatak riješili upotrebom dinamički alociranog polja zamijenite ga vektorom kompleksnih brojeva te
sortirajte upotrebom funkcije `std::sort` (zaglavlje algorithm).
