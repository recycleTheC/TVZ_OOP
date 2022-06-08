# Zavr�ni kolokvij

Napomena: **tekstovi zadataka nisu precizni - rekonstrukcija po sje�anju!**

Napi�ite klasu `Nalaziste` koja sard�ava ime i lokaciju nalazi�ta, te niz koji sadr�ava
sirovine koje se nalaze na tom nalazi�tu. Klasa `Sirovima` sadr�ava naziv, koli�inu
sirovine na nalazi�tu te cijenu sirovine izra�enu u kn/kg.

a) Napi�ite konstruktor koji prima naziv i lokaciju za klasu `Nalaziste`, te konstruktor
koji prima naziv, kolicinu i cijenu za klasu `Sirovina`.
Za klasu `Nalaziste` jo� napi�ite konstruktor koji �e uz naziv i lokaciju primati i neograni�en
broj sirovina - napi�ite ga izvan klase. 

b) Napi�ite preoptere�enje za `operator <<` tako da ispisuje sve sirovine iz klase `Nalaziste`
sortirane tako da se prvo ispi�u sirovine s najmanjom cijenom. **(4 boda)** Ako se u sortiranju koristi
lambda funkcija, dobije se jo� **1 bod**.

c) Implementirajte enkapsulaciju unutar klase `Sirovina` tako da se cijena sirovine ne
mo�e postaviti na vrijednost koja nije unutar intervala [3,100]. Ako se poku�a postaviti
cijena koja nije iz intervala, potrebno je baciti iznimku tipa IznimkaCijena koja �e ispisati
poruku o pogre�noj cijeni i redni broj iznimke koja je ba�ena, npr. "Iznimka 1: Cijena od 2.75 kn nije ispravna!"

d) Postoje primarna i sekundarna nalazi�ta sirovina. Razlikuju se po kona�noj cijeni sirovine koja
uklju�uje tro�kove prijevoza. Kod primarnih nalazi�ta cijena sirovine uve�ava za 0.40 kn za svaki kg
sirovine koji se preveze, a kod sekundarnih za 0.85 kn.
Napi�ite globalnu funkciju `double UkupnaCijenaSirovina(vector<Nalaziste*>& nalazista)` koja
�e vratiti ukupnu cijenu sirovina koja se nalaze u nalazi�tima iz vektora.

e) Napisati klasu `TerminalSirovina` koja sadr�ava niz pokaziva�a na 
objekta klase `Sirovina`. U klasi implementirati prijenosni konstruktor 
i operator pridru�ivanja sa kopiranjem. (Ako se u klasi ne napi�e odgovaraju�i
destruktor oduzima se 1 bod)