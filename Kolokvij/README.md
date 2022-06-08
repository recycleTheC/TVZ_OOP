# Završni kolokvij

Napomena: **tekstovi zadataka nisu precizni - rekonstrukcija po sjećanju!**

Napišite klasu `Nalaziste` koja sardžava ime i lokaciju nalazišta, te niz koji sadržava
sirovine koje se nalaze na tom nalazištu. Klasa `Sirovina` sadržava naziv, količinu
sirovine na nalazištu te cijenu sirovine izraženu u kn/kg.

a) Napišite konstruktor koji prima naziv i lokaciju za klasu `Nalaziste`, te konstruktor
koji prima naziv, kolicinu i cijenu za klasu `Sirovina`.
Za klasu `Nalaziste` još napišite konstruktor koji će uz naziv i lokaciju primati i neograničen
broj sirovina - napišite ga izvan klase. 

b) Napišite preopterećenje za `operator <<` tako da ispisuje sve sirovine iz klase `Nalaziste`
sortirane tako da se prvo ispišu sirovine s najmanjom cijenom. **(4 boda)** Ako se u sortiranju koristi
lambda funkcija, dobije se još **1 bod**.

c) Implementirajte enkapsulaciju unutar klase `Sirovina` tako da se cijena sirovine ne
može postaviti na vrijednost koja nije unutar intervala [3,100]. Ako se pokuša postaviti
cijena koja nije iz intervala, potrebno je baciti iznimku tipa IznimkaCijena koja će ispisati
poruku o pogrešnoj cijeni i redni broj iznimke koja je bačena, npr. "Iznimka 1: Cijena od 2.75 kn nije ispravna!"

d) Postoje primarna i sekundarna nalazišta sirovina. Razlikuju se po konačnoj cijeni sirovine koja
uključuje troškove prijevoza. Kod primarnih nalazišta cijena sirovine uvećava za 0.40 kn za svaki kg
sirovine koji se preveze, a kod sekundarnih za 0.85 kn.
Napišite globalnu funkciju `double UkupnaCijenaSirovina(vector<Nalaziste*>& nalazista)` koja
će vratiti ukupnu cijenu sirovina koja se nalaze u nalazištima iz vektora.

e) Napisati klasu `TerminalSirovina` koja sadržava niz pokazivača na 
objekta klase `Sirovina`. U klasi implementirati prijenosni konstruktor 
i operator pridruživanja sa kopiranjem. (Ako se u klasi ne napiše odgovarajući
destruktor oduzima se 1 bod)
