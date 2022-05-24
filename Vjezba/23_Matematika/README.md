# 23. Matematika

Neka postoji sljedeći programski odsječak:

```cpp
int main() {
	Matematika Racun;
	cout << Racun.suma(2, 4.3) << endl; // 6.3
	cout << Racun.suma(2.3, 4) << endl; // 6.3
	cout << Racun.suma(Kompleksni(2.5, 1), 4) << endl; // 6.5 1i
	
	return 0;
}
```

Napišite sve potrebne klase, metode i funkcije kako bi prikazani programski odsječak radio kao što je to u komentarima i predviđeno.
Napomena: metoda suma vraća sumu bilo koja dva podatka koje je moguće zbrojiti operatorom +. Za tipove podatka koje nije moguće direktno
zbrojiti operatorom + potrebno je preopteretiti taj operator za navedeni tip.