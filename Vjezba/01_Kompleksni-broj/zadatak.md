# 1. Kompleksni broj

Napi�ite program koji u dinami�ki alocirano polje u�itava N kompleksnih brojeva te ih ispisuje 
sortirane po vrijednosti njihovih modula (od najmanjeg prema najve�em).

- Kompleksni broj treba predstaviti klasom Kompleksni koja sadr�i realni i imaginarni dio (realni brojevi).
- Modul kompleksnog broja je udaljenost kompleksnog broja od ishodi�ta i treba se ra�unati globalnom funkcijom Modul.
- Za sortiranje kompleksnih brojeva napi�ite funkciju Sortiraj koja �e sortirati kompleksne brojeve upotrebom BubbleSort algoritma.

## Primjer izvo�enja

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

Nakon �to ste zadatak rije�ili upotrebom dinami�ki alociranog polja zamijenite ga vektorom kompleksnih brojeva te
sortirajte upotrebom funkcije `std::sort` (zaglavlje algorithm).