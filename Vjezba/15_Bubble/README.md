# 15. Bubble

Potrebno je napisati klasu Bubble sa svojstvima boja i radijus.
Implementacijom operatora zbrajanja (+) potrebno je omogućiti "spajanje" dva bubble-a u jedan.
Novi bubble ima obujam jednak zbroju obujama bubble-a od kojih je nastao, a preuzima boju većeg bubble-a.
Pri izdvajanju novog bubble-a iz postojećeg (operator -) nastaje novi sa smanjenim obujmom. Boja ostaje od originalnog bubble-a.

Obujam se računa prema obujmu kugle - V = 4/3 * r * r * r * PI. Također, treći korjen se računa kao pow(x, 1.0/3) (potrebno pri izračunavanju radijusa iz obujma).

Potrebno je dodati i operator == koji uspoređuje dva Bubble objekta. Dva bubble-a su isti ako imaju istu boju, i ako im se radijus razlikuje za ne više od 0.0001.

```cpp
int main() {
	Bubble a("blue", 10.4);
	Bubble b("red", 7.2);
	Bubble c("green", 18.8);

	Bubble x = a + b; //nastat će novi bubble obujma 6275.27
	cout << x; //blue: 11.44
	Bubble y = x + c;
	cout << y; //green: 20.12

	Bubble z = y - x;
	cout << z; //green: 18.8

	if (z == c)
		cout << "OK" << endl; //OK

	return 0;
}
```